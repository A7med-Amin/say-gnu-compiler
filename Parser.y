/* Part 1: Definitions */

%{
    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(char* s);
    int yylex(void);
    extern FILE *yyin;
%}

%union{
    int ival;
    float fval;
    char cval;
    char* sval;
    char* bval;
}

/* Data Types */
%token INT FLOAT CHAR STRING BOOL CONST VOID

/* Keywords */
%token IF ELSE SWITCH CASE DEFAULT WHILE FOR REPEAT UNTIL BREAK CONTINUE RETURN ENUM

/* Identifiers */
%token IDENTIFIER

/* Values */
    /* Boolean */
%token <bval> BOOLEAN_TRUE 
%token <bval> BOOLEAN_FALSE 
    /* Integer */
%token <ival> INTEGER
    /* Float */
%token <fval> FLOATING
    /* Character */
%token <cval> CHARACTER
    /* String */
%token <sval> STRING_LITERAL

/* Operators */
    /* Arithmetic */
%token ADD SUB MUL DIV MOD INC DEC POW ASSIGN
    /* Logical */
%token AND OR NOT 
    /* Comparison */
%token EQ NEQ GT LT GTE LTE

/* Print */
%token PRINT

// Associativity
%left EQ NEQ GT LT GTE LTE
%left ADD SUB 
%left MUL DIV MOD
%right ASSIGN POW
%nonassoc AND OR NOT



/* Part 1 End */

%%

/* Part 2: Patterns and Action Rules */

program:                                                                            {printf("========  PROGRAM START ***********\n");}
        | codeBlock                                                                 {printf("========  codeBlock ***********\n");}
        ;


codeStatement: dataType IDENTIFIER ';'                                              {printf("========  VARIABLE DECLARATION ***********\n");}
        | dataType IDENTIFIER ASSIGN expression ';'                                 {printf("========  VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\n");}
        | IDENTIFIER ASSIGN expression ';'                                          {printf("========  VARIABLE ASSIGNMENT ***********\n");}
        | CONST dataType IDENTIFIER ASSIGN constValue ';'                           {printf("========  CONSTANT VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\n");}
        /* | WHILE '(' expression ')' codeBlock                                        {printf("========  WHILE LOOP ***********\n");}    */
        /* | codeBlock                                                                 {printf("========  BLOCK ***********\n");}   */
        /* | REPEAT codeBlock UNTIL '(' expression ')'                                 {printf("========  REPEAT UNTILL ***********\n");}   */
        /* | FOR '(' forLoopInitialization expression ';' expression ')' codeBlock     {printf("========  FOR LOOP ***********\n");}  */
        | PRINT '(' printStatement ')' ';'                                          {printf("========  PRINT STATEMENT ***********\n");}
        | IF expression scopeBlock                                                  {printf("========  IF STATEMENT ***********\n");}
        | IF expression scopeBlock ELSE scopeBlock                                  {printf("========  IF ELSE STATEMENT ***********\n");}
        | error   { yyerror("Unexpected statement."); }
        ;

dataType: INT {} 
        | FLOAT {} 
        | CHAR {}
        | STRING {}
        | BOOL {}
        ;

simpleNumericalDataValue: INTEGER                               {printf("========  INTEGER NUMBER %d ***********\n", $1);}
        | FLOATING                                              {printf("========  FLOAT NUMBER %f ***********\n", $1);}
        ;

simpleNonNumericalDataValue: CHARACTER                          {printf("========  CHAR ***********\n");}
        | STRING_LITERAL                                        {printf("========  STRING ***********\n");}
        | BOOLEAN_TRUE                                          {printf("========  TRUE BOOLEAN ***********\n");}
        | BOOLEAN_FALSE                                         {printf("========  FALSE BOOLEAN ***********\n");}
        ;

complexNumericalValue: simpleNumericalDataValue {}
        | IDENTIFIER {printf("========  IDENTIFIER ***********\n");}
        | complexNumericalValue ADD complexNumericalValue {printf("========  ADDITION OPERATION ***********\n");}
        | complexNumericalValue SUB complexNumericalValue {printf("========  SUBTRACTION OPERATION ***********\n");}
        | complexNumericalValue MUL complexNumericalValue {printf("========  MULTIPLICATION OPERATION ***********\n");}
        | complexNumericalValue DIV complexNumericalValue {printf("========  DIVISION OPERATION ***********\n");}
        | complexNumericalValue MOD complexNumericalValue {printf("========  MODULUS OPERATION ***********\n");}
        | IDENTIFIER INC             {printf("========  INCREMENT ***********\n");}
        | IDENTIFIER DEC             {printf("========  DECREMENT ***********\n");}
        | '(' complexNumericalValue ')' {printf("========  PARENTHESIS ***********\n");}
        ;

LogicalOperation: expression AND expression
        | expression OR expression {printf("========  OR OPERATION ***********\n");}
        | dataValue EQ dataValue   {printf("========  EQUAL OPERATION ***********\n");}
        | dataValue NEQ dataValue  {printf("========  NOT EQUAL OPERATION ***********\n");}
        | expression GT expression {printf("========  GREATER THAN OPERATION ***********\n");}
        | expression LT expression {printf("========  LESS THAN OPERATION ***********\n");}
        | expression GTE expression {printf("========  GREATER THAN OR EQUAL OPERATION ***********\n");}
        | expression LTE expression {printf("========  LESS THAN OR EQUAL OPERATION ***********\n");}
        | NOT expression         {printf("========  NOT OPERATION ***********\n");}
        ;




dataValue: complexNumericalValue {}
        | simpleNonNumericalDataValue {}
        | LogicalOperation {}
        ;

constValue: simpleNonNumericalDataValue                         {printf("========  const simpleNonNumericalDataValue ***********\n");}
        | simpleNumericalDataValue                              {printf("========  const simpleNumericalDataValue ***********\n");}
        ;

/* forLoopInitialization: dataType IDENTIFIER ASSIGN expression ';'
        | IDENTIFIER ASSIGN expression ';'
        ; */
        
expression: dataValue {}
        ;

printStatement: expression ',' printStatement   {printf("========  expression ',' printStatement ***********\n");}
        | expression                            {printf("========  expression ***********\n");}
        ;   

codeBlock: codeStatement                        {printf("========  codeStatement ***********\n");}
        |  codeBlock codeStatement              {printf("========  codeBlock codeStatement ***********\n");}
        ;

scopeBlock: '{' '}'
    | '{' codeStatement '}'

/* Part 2 End */

%%

/* Part 3: Subroutines */

void yyerror(char* s){
    fprintf(stderr, "\nERROR MESS: %s\n", s);
}

int main(int argc, char **argv) {
    FILE *file;

    // Check if a filename was provided
    if (argc > 1) {
        // File name provided, open the file for reading
        file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        // Set Flex to read from it instead of standard input:
        yyin = file;
    } 
    /* else {
        // No filename provided, read from standard input
        yyin = stdin;
    } */

    // Parse through the input:
    yyparse();

    if (argc > 1) {
        // Close the file if it was opened
        fclose(file);
    }

    return 0;
}

/* Part 3 End */