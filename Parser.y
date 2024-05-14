/* Part 1: Definitions */

%{
    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    /* Header Files */
    #include "semantic_analyzer.hpp"

    /* Function prototypes */
    void yyerror(const char* s);
    int yylex(void);
    int yylineno;     /* from lexer represents line numbers */
    extern FILE *yyin;

    void printRed(const char *text) {
    printf("\033[31m%s\033[0m\n", text);
    }

    void printBlue(const char *text) {
        printf("\033[34m%s\033[0m\n", text);
    }

    void printMagenta(const char *text) {
        printf("\033[35m%s\033[0m\n", text);
    }
    void printYellow(const char *text) {
        printf("\033[33m%s\033[0m\n", text);
    }

    void printGreen(const char *text) {
        printf("\033[92m%s\033[0m\n", text);
    }

    void printCyan(const char *text) {
        printf("\033[36m%s\033[0m\n", text);
    }

    void printGray(const char *text) {
        printf("\033[90m%s\033[0m\n", text);
    }
%}

%union{
    int dataType;
    char * stringVal;
    struct ActualValue{
        int type;
        char* nameRep;
        union{
            int ival;
            float fval;
            char cval;
            char* sval;
            bool bval;
        };
    }actualValue;
}

/* Program Grammer Types */
%type <actualValue> simpleNumericalDataValue
%type <actualValue> simpleNonNumericalDataValue
%type <actualValue> constValue
%type <actualValue> complexNumericalValue
%type <actualValue> LogicalOperation
%type <actualValue> expression
%type <actualValue> functionCall



/* Data Types */
%type <dataType> dataType
%token<dataType> INT_TYPE 
%token<dataType> FLOAT_TYPE 
%token<dataType> CHAR_TYPE 
%token<dataType> STRING_TYPE 
%token<dataType> BOOL_TYPE 

/* Keywords */
%token CONSTANT VOID_TYPE
%token IF ELSE SWITCH CASE DEFAULT WHILE FOR REPEAT UNTIL BREAK RETURN

/* Identifiers */
%token <stringVal> IDENTIFIER
/* Values */
    /* Boolean */
%token <actualValue> BOOLEAN_TRUE 
%token <actualValue> BOOLEAN_FALSE 
    /* Integer */
%token <actualValue> INTEGER_VALUE
    /* Float */
%token <actualValue> FLOATING
    /* Character */
%token <actualValue> CHARACTER
    /* String */
%token <actualValue> STRING_LITERAL

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

program:                                                                                    {printf("======== EMPTY PROGRAM ***********\n");}
        | codeBlock                                                                         {    
                                                                                                printf("                 #_   _#\n");
                                                                                                printf("                 |a` `a|\n");
                                                                                                printf("                 |  u  |\n");
                                                                                                printf("                 \\  =  /\n");
                                                                                                printf("                 |\\___/|\n");
                                                                                                printf("        ___ ____/:     :\\____ ___\n");
                                                                                                printf("      .'   `.-===-\\   /-===-.`   '.\n");
                                                                                                printf("     /      .-\"\"\"\"\"-.-\"\"\"\"\"-.      \\\n");
                                                                                                printf("    /'             =:=             '\\\n");
                                                                                                printf("  .'  ' .:    o   -=:=-   o    :. '  `.\n");
                                                                                                printf("  (.'   /'. '-.....-'-.....-' .\\'   '.)\n");
                                                                                                printf("  /' ._/   \".     --:--     .\"   \\_. '\\\n");
                                                                                                printf(" |  .'|      \".  ---:---  .\"      |'.  |\n");
                                                                                                printf(" |  : |       |  ---:---  |       | :  |\n");
                                                                                                printf("  \\ : |       |_____._____|       | : /\n");
                                                                                                printf("  /   (       |----|------|       )   \\\n");
                                                                                                printf(" /... .|      |    |      |      |. ...\\\n");
                                                                                                printf("|::::/'' jgs /     |       \\     ''\\::::|\n");
                                                                                                printf("'\"\"\"\"       /'    .L_      `\\       \"\"\"\"'\n");
                                                                                                printf("           /'-.,__/` `\\__..-'\\\n");
                                                                                                printf("          ;      /     \\      ;\n");
                                                                                                printf("          :     /       \\     |\n");
                                                                                                printf("          |    /         \\.   |\n");
                                                                                                printf("          |`../           |  ,/\n");
                                                                                                printf("          ( _ )           |  _)\n");
                                                                                                printf("          |   |           |   |\n");
                                                                                                printf("          |___|           \\___|\n");
                                                                                                printf("          :===|            |==|\n");
                                                                                                printf("           \\  /            |__|\n");
                                                                                                printf("           /\\/\\           /\"\"\"`8.__\n");
                                                                                                printf("           |oo|           \\__.//___)\n");
                                                                                                printf("           |==|\n");
                                                                                                printf("           \\__/\n");
                                                                                                printf("                       SALAMO ALEEKO! ")
                                                                                            }
        ;


codeStatement: dataType IDENTIFIER ';'                                                      
            {
                SymbolTableEntry* entry = identifierScopeCheck($2);
                if(entry != nullptr){
                        writeSemanticError("Already declared variable within this scope",yylineno);
                        return 0;
                }
            }
        | dataType IDENTIFIER ASSIGN expression ';'                                         {printf("\033[33m========  VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | IDENTIFIER ASSIGN expression ';'                                                  {printf("\033[33m========  VARIABLE ASSIGNMENT ***********\033[0m\n");}
        | CONSTANT dataType IDENTIFIER ASSIGN constValue ';'                                   {printf("\033[33m========  CONSTANT VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | WHILE '(' expression ')' scopeBlock                                               {printBlue("========  WHILE LOOP ***********");}   
        | REPEAT scopeBlock UNTIL '(' expression ')' ';'                                      {printBlue("========  REPEAT UNTILL ***********");}  
        | FOR '(' {createNewSymbolTable();} forLoopInitialization expression ';' expression ')' loopsScopeBlock            {printBlue("========  FOR LOOP ***********");} 
        | PRINT '(' printStatement ')' ';'                                                  {printf("========  PRINT STATEMENT ***********\033[0m\n");}
        | IF '(' expression ')' scopeBlock                                                  {printBlue("========  IF STATEMENT ***********");}
        | IF '(' expression ')' scopeBlock ELSE scopeBlock                                  {printBlue("========  IF ELSE STATEMENT ***********");}
        | IF '(' expression ')' scopeBlock elseIfStmnt                                      {printBlue("========  IF ELSE IF STATEMENT ***********");}
        | SWITCH '(' IDENTIFIER ')' switchBlock                                             {printBlue("========  SWITCH CASE ***********");}
        | function                                                                          {printf("========  FUNCTION DECLARATION ***********\n");}
        | functionCall  ';'                                                                 {printf("========  FUNCTION CALL ***********\n");}
        | dataType IDENTIFIER ASSIGN functionCall ';'                                       {printf("========  DECLARE AND ASSIGNMENT WITH FUNCTION ***********\n");}
        | IDENTIFIER ASSIGN functionCall ';'   
        | scopeBlock
        | error                                                                             { yyerror("Unexpected statement."); }
        ;

elseIfStmnt: ELSE IF '(' expression ')' scopeBlock elseIfStmnt
        | ELSE IF '(' expression ')' scopeBlock
        | ELSE scopeBlock
        |
        ;

dataType: INT_TYPE {} 
        | FLOAT_TYPE {} 
        | CHAR_TYPE {}
        | STRING_TYPE {}
        | BOOL_TYPE {}
        ;

simpleNumericalDataValue: INTEGER_VALUE                                                           {printf("\033[36m========  INTEGER (%d) ***********\033[0m\n", $1);}
        | FLOATING                                                                          {printf("========  FLOAT (%f) ***********\n", $1);}
        ;

simpleNonNumericalDataValue: CHARACTER                          {printYellow("========  CHAR ***********\n");}
        | STRING_LITERAL                                        {printYellow("========  STRING ***********\n");}
        | BOOLEAN_TRUE                                          {printYellow("========  TRUE BOOLEAN ***********\n");}
        | BOOLEAN_FALSE                                         {printYellow("========  FALSE BOOLEAN ***********\n");}
        ;

complexNumericalValue: simpleNumericalDataValue                 
        | IDENTIFIER                                            {printGray("========  IDENTIFIER ***********");}
        | complexNumericalValue ADD complexNumericalValue       {printMagenta("========  ADDITION OPERATION ***********");}
        | complexNumericalValue SUB complexNumericalValue       {printMagenta("========  SUBTRACTION OPERATION ***********");}
        | complexNumericalValue MUL complexNumericalValue       {printMagenta("========  MULTIPLICATION OPERATION ***********");}
        | complexNumericalValue DIV complexNumericalValue       {printMagenta("========  DIVISION OPERATION ***********");}
        | complexNumericalValue MOD complexNumericalValue       {printMagenta("========  MODULUS OPERATION ***********");}
        | complexNumericalValue POW complexNumericalValue       {printMagenta("========  POWER OPERATION ***********");}
        | IDENTIFIER INC                                        {printMagenta("========  INCREMENT ***********");}
        | IDENTIFIER DEC                                        {printMagenta("========  DECREMENT ***********");}
        | INC IDENTIFIER                                        {printMagenta("========  INCREMENT ***********");}
        | DEC IDENTIFIER                                        {printMagenta("========  DECREMENT ***********");}
        /* | '(' complexNumericalValue ')'                         {printf("========  PARENTHESIS ***********\n");} */
        ;

LogicalOperation: expression AND expression                     {printGreen("========  AND OPERATION ***********");}
        | expression OR expression                              {printGreen("========  OR OPERATION ***********");}
        | expression EQ expression                              {printGreen("========  EQUAL OPERATION ***********");}
        | expression NEQ expression                             {printGreen("========  NOT EQUAL OPERATION ***********");}
        | expression GT expression                              {printGreen("========  GREATER THAN OPERATION ***********");}
        | expression LT expression                              {printGreen("========  LESS THAN OPERATION ***********");}
        | expression GTE expression                             {printGreen("========  GREATER THAN OR EQUAL OPERATION ***********");}
        | expression LTE expression                             {printGreen("========  LESS THAN OR EQUAL OPERATION ***********");}
        /* | '(' LogicalOperation ')'                              {printf("========  PARENTHESIS ***********\n");} */
        | NOT expression                                        {printGreen("========  NOT OPERATION ***********");}
        ;


expression: complexNumericalValue                                
        | simpleNonNumericalDataValue                           
        | LogicalOperation
        | '(' complexNumericalValue ')'
        | '(' simpleNonNumericalDataValue ')'                                       
        | '(' LogicalOperation ')'                                       
        ;

constValue: simpleNonNumericalDataValue                         
        | simpleNumericalDataValue                              
        ;

forLoopInitialization: dataType IDENTIFIER ASSIGN expression ';'   
        | IDENTIFIER ASSIGN expression ';'                         
        ;

printStatement: expression ',' printStatement                       
        | expression                                                
        ;   

codeBlock: codeStatement                                            {}
        |  codeBlock codeStatement                                  {}
        ;

scopeBlock: '{' {createNewSymbolTable();} codeBlock {scopeEnd();} '}'                                             {printf("========  SCOPE ***********\n");}
    ;

loopsScopeBlock: '{' codeBlock {scopeEnd();} '}'                                                                  {printf("========  LOOPS SCOPE ***********\n");}
    ;

/////////////////////////////// Switch Case ///////////////////////////////

switchBlock: '{' {createNewSymbolTable();} caseExpression {scopeEnd();} '}'                     
    ;

caseExpression:	
            caseDefault 	                   
    |       CASE expression ':' codeBlock BREAK ';' caseExpression  
	;

caseDefault:
            DEFAULT ':' codeBlock BREAK ';'    		            	 
            | DEFAULT ':' codeBlock    		                    	 
            |                                                       	 
    ;

/////////////////////////////// Function ///////////////////////////////

function :  dataType IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock RETURN  expression ';' {scopeEnd();} '}'  {printf("========  FUNCTION ***********\n");}
        |   VOID_TYPE IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock returnCase {scopeEnd();} '}'             {printf("========  VOID FUNCTION ***********\n");}
        ;

returnCase: RETURN ';'    		                                                                {printf("========  VOID FUNCTION RETURN ***********\n");}	 
        |                                                                                       {printf("========  NO VOID FUNCTION RETURN ***********\n");}	 
        ;

functionCall: IDENTIFIER '(' callList ')'   		                                            {printf("========  FUNCTION CALL ***********\n");}
        ;

callList:  complexNumericalValue ',' callList {}
	    |  complexNumericalValue              {}
        | functionCall                  /* Recursive Call or nested function call */
		| 
	    ;	

argList:  dataType IDENTIFIER ',' argList {}
	    | dataType IDENTIFIER 		      {}
		|                                 {}
	    ;

/* Part 2 End */

%%

/* Part 3: Subroutines */




void yyerror(const char* s){
    fprintf(stderr, "\nERROR MESS: %s\n", s);
}

int main(int argc, char **argv) {
    // Initialize the symbol table
    initSymbolTable();
    
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

    // Save the symbol tables
    saveSymbolTables();

    return 0;
}

/* Part 3 End */