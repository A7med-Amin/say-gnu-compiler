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


codeStatement: dataType IDENTIFIER ';'                                              {printf("\033[33m========  VARIABLE DECLARATION ***********\033[0m\n");}
        | dataType IDENTIFIER ASSIGN expression ';'                                 {printf("\033[33m========  VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | IDENTIFIER ASSIGN expression ';'                                          {printf("\033[33m========  VARIABLE ASSIGNMENT ***********\033[0m\n");}
        | CONST dataType IDENTIFIER ASSIGN constValue ';'                           {printf("\033[33m========  CONSTANT VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | WHILE expression scopeBlock                                               {printf("\033[32m========  WHILE LOOP ***********\033[0m\n");}   
        /* | codeBlock                                                                 {printf("========  BLOCK ***********\n");}   */
        | REPEAT scopeBlock UNTIL expression                                        {printf("========  REPEAT UNTILL ***********\n");}  
        | FOR '(' forLoopInitialization expression ';' expression ')' scopeBlock    {printf("\033[32m========  FOR LOOP ***********\033[0m\n");} 
        | PRINT '(' printStatement ')' ';'                                          {printf("========  PRINT STATEMENT ***********\033[0m\n");}
        | IF expression scopeBlock                                                  {printf("\033[35m========  IF STATEMENT ***********\033[0m\n");}
        /* | expression                                                                {printf("========  EXPRESSION ***********\n");} */
        | IF expression scopeBlock ELSE scopeBlock                                  {printf("\033[35m========  IF ELSE STATEMENT ***********\033[0m\n");}
        | error   { yyerror("Unexpected statement."); }
        ;

dataType: INT {} 
        | FLOAT {} 
        | CHAR {}
        | STRING {}
        | BOOL {}
        ;

simpleNumericalDataValue: INTEGER                               {printf("\033[36m========  INTEGER NUMBER %d ***********\033[0m\n", $1);}
        | FLOATING                                              {printf("========  FLOAT NUMBER %f ***********\n", $1);}
        ;

simpleNonNumericalDataValue: CHARACTER                          {printf("========  CHAR ***********\n");}
        | STRING_LITERAL                                        {printf("========  STRING ***********\n");}
        | BOOLEAN_TRUE                                          {printf("========  TRUE BOOLEAN ***********\n");}
        | BOOLEAN_FALSE                                         {printf("========  FALSE BOOLEAN ***********\n");}
        ;

complexNumericalValue: simpleNumericalDataValue                 {printf("\033[90m========  simpleNumericalDataValue ***********\033[0m\n");}
        | IDENTIFIER                                            {printf("========  IDENTIFIER ***********\n");}
        | complexNumericalValue ADD complexNumericalValue       {printf("========  ADDITION OPERATION ***********\n");}
        | complexNumericalValue SUB complexNumericalValue       {printf("========  SUBTRACTION OPERATION ***********\n");}
        | complexNumericalValue MUL complexNumericalValue       {printf("========  MULTIPLICATION OPERATION ***********\n");}
        | complexNumericalValue DIV complexNumericalValue       {printf("========  DIVISION OPERATION ***********\n");}
        | complexNumericalValue MOD complexNumericalValue       {printf("========  MODULUS OPERATION ***********\n");}
        | complexNumericalValue POW complexNumericalValue       {printf("========  POWER OPERATION ***********\n");}
        | IDENTIFIER INC                                        {printf("========  INCREMENT ***********\n");}
        | IDENTIFIER DEC                                        {printf("========  DECREMENT ***********\n");}
        | '(' complexNumericalValue ')'                         {printf("========  PARENTHESIS ***********\n");}
        ;

dataValue: complexNumericalValue                                {printf("\033[90m========  complexNumericalValue ***********\033[0m\n");}
        | simpleNonNumericalDataValue                           {printf("\033[90m========  simpleNonNumericalDataValue ***********\033[0m\n");}
        ;

constValue: simpleNonNumericalDataValue                         {printf("========  const simpleNonNumericalDataValue ***********\n");}
        | simpleNumericalDataValue                              {printf("========  const simpleNumericalDataValue ***********\n");}
        ;

forLoopInitialization: dataType IDENTIFIER ASSIGN expression ';'
        | IDENTIFIER ASSIGN expression ';'
        ;
        
expression: dataValue                           {printf("\033[90m========  dataValue ***********\033[0m\n");}
        ;

printStatement: expression ',' printStatement   {printf("========  expression ',' printStatement ***********\n");}
        | expression                            {printf("========  expression ***********\n");}
        ;   

codeBlock: codeStatement                        {printf("========  codeStatement ***********\n");}
        |  codeBlock codeStatement              {printf("========  codeBlock codeStatement ***********\n");}
        ;

scopeBlock: '{' '}'                             {printf("========  EMPTY SCOPE ***********\n");}
    | '{' codeStatement '}'                     {printf("========  SCOPE ***********\n");}

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