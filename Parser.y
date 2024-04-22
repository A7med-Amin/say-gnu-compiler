/* Part 1: Defniitions */

%{
    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(char* s);
    int yylex(void);
%}

%union{
    int ival;
    float fval;
    char cval;
    char* sval;
    bool bval;
}

/* Data Types */
%token INT FLOAT CHAR STRING BOOL CONST VOID

/* Keywords */
%token IF ELSE SWITCH CASE DEFAULT WHILE FOR REPEAT UNTIL BREAK CONTINUE RETURN ENUM

/* Identifiers */
%token IDENTIFIER

/* Values */
    /* Boolean */
%token <bval> BOOLEAN 
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



/* Part 2 End */

%%

/* Part 3: Subroutines */

void yyerror(char* s){
    printf(stderr, "\nERROR MESS: %s\n", s);
    exit(1);
}

int main(){
    yyparse();
    return 0;
}

/* Part 3 End */