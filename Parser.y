/* Part 1: Definitions */

%{
    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(char* s);
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
    int ival;
    float fval;
    char cval;
    char* sval;
    char* bval;
    char* id;
}

/* Data Types */
%token INT FLOAT CHAR STRING BOOL CONST VOID

/* Keywords */
%token IF ELSE SWITCH CASE DEFAULT WHILE FOR REPEAT UNTIL BREAK RETURN

/* Identifiers */
%token <id> IDENTIFIER

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

program:                                                                                    {printf("========  PROGRAM START ***********\n");}
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


codeStatement: dataType IDENTIFIER ';'                                                      {printf("\033[33m========  VARIABLE DECLARATION ***********\033[0m\n");}
        | dataType IDENTIFIER ASSIGN expression ';'                                         {printf("\033[33m========  VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | IDENTIFIER ASSIGN expression ';'                                                  {printf("\033[33m========  VARIABLE ASSIGNMENT ***********\033[0m\n");}
        | CONST dataType IDENTIFIER ASSIGN constValue ';'                                   {printf("\033[33m========  CONSTANT VARIABLE DECLARATION WITH VALUE ASSIGNMENT ***********\033[0m\n");}
        | WHILE '(' expression ')' scopeBlock                                               {printBlue("========  WHILE LOOP ***********");}   
        | REPEAT scopeBlock UNTIL '(' expression ')'                                        {printBlue("========  REPEAT UNTILL ***********");}  
        | FOR '(' forLoopInitialization expression ';' expression ')' scopeBlock            {printBlue("========  FOR LOOP ***********");} 
        | PRINT '(' printStatement ')' ';'                                                  {printf("========  PRINT STATEMENT ***********\033[0m\n");}
        | IF '(' expression ')' scopeBlock                                                  {printBlue("========  IF STATEMENT ***********");}
        | IF '(' expression ')' scopeBlock ELSE scopeBlock                                  {printBlue("========  IF ELSE STATEMENT ***********");}
        | SWITCH '(' IDENTIFIER ')' switchBlock                                             {printBlue("========  SWITCH CASE ***********");}
        | function                                                                          {printf("========  FUNCTION DECLARATION ***********\n");}
        | functionCall  ';'                                                                 {printf("========  FUNCTION CALL ***********\n");}
        | dataType IDENTIFIER ASSIGN functionCall ';'                                       {printf("========  DECLARE AND ASSIGNMENT WITH FUNCTION ***********\n");}
        | IDENTIFIER ASSIGN functionCall ';'   
        | error   { yyerror("Unexpected statement."); }
        ;

dataType: INT {} 
        | FLOAT {} 
        | CHAR {}
        | STRING {}
        | BOOL {}
        ;

simpleNumericalDataValue: INTEGER                                                           {printf("\033[36m========  INTEGER (%d) ***********\033[0m\n", $1);}
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

codeBlock: codeStatement                                            {printRed("========  END OF CODEBLOCK ***********\n");}
        |  codeBlock codeStatement                                  {printRed("========  END OF CODEBLOCK ***********\n");}
        ;

scopeBlock: '{' '}'                                                 {printf("========  EMPTY SCOPE ***********\n");}
    | '{' codeStatement '}'                                         {printf("========  SCOPE ***********\n");}
    | '{' expression ';' '}'                                        {printf("========  SCOPE ***********\n");}

    ;


switchBlock: '{' caseExpression '}'                     
    ;

caseExpression:	
            caseDefault 	                   
    |       CASE expression ':' codeStatement BREAK ';' caseExpression  
	;

caseDefault:
            DEFAULT ':' codeStatement BREAK ';'    		            	 
            | DEFAULT ':' codeStatement    		                    	 
            |                                                       	 
    ;

function :  dataType IDENTIFIER '(' argList ')' '{' codeStatement RETURN  expression ';' '}'    {printf("========  FUNCTION ***********\n");}
        |   VOID IDENTIFIER '(' argList ')' '{' codeStatement returnCase '}'                    {printf("========  VOID FUNCTION ***********\n");}
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