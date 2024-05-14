/* Part 1: Definitions */

%{
    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    /* communications with yacc */
    #include "Parser.tab.h"
    extern void yyerror(const char* s);
    extern int yylineno;
	int yylex();

%}

/* Part 1 End */

%%

    /* Part 2: Regex and Action Rules */

    /* Data Types */
"int"                       {return INT_TYPE;}
"float"                     {return FLOAT_TYPE;}
"char"                      {return CHAR_TYPE;}
"string"                    {return STRING_TYPE;}
"bool"                      {return BOOL_TYPE;}

    /* Keywords */
"const"                     {return CONSTANT;}
"void"                      {return VOID_TYPE;}

    /* Keywords */
        /* Consitions */
"if"                        {return IF;}
"else"                      {return ELSE;}
"switch"                    {return SWITCH;}
"case"                      {return CASE;}
"default"                   {return DEFAULT;}
        /* Loops */
"while"                     {return WHILE;}
"for"                       {return FOR;}
"repeat"                    {return REPEAT;}
"until"                     {return UNTIL;}
"break"                     {return BREAK;}
        /* General Keywords */
"return"                    {return RETURN;}

    /* Print */
"print"                     {return PRINT;}

    /* Operators */
        /* Arithmetic */
"+"                         {return ADD;}
"-"                         {return SUB;}
"*"                         {return MUL;}
"/"                         {return DIV;}
"%"                         {return MOD;}
"++"                        {return INC;}
"--"                        {return DEC;}
"**"                        {return POW;}
"="                         {return ASSIGN;}

        /* Logical */
"&&"                        {return AND;}
"||"                        {return OR;}
"!"                         {return NOT;}

        /* Comparison */
"=="                        {return EQ;}
"!="                        {return NEQ;}
"<"                         {return LT;}
"<="                        {return LTE;}
">"                         {return GT;}
">="                        {return GTE;}

    /* Variable Values  and Identifier*/
            /* Boolean Variable */
"true"                         { yylval.bval = "true"; return BOOLEAN_TRUE; }
"false"                        { yylval.bval = "false"; return BOOLEAN_FALSE; }

    /* Identifiers */
[a-zA-Z_][a-zA-Z0-9_]*      {yylval.sval = (yytext); return IDENTIFIER;}

        /* Integer Variable */
[0-9]+                      {yylval.ival = atoi(yytext); return INTEGER_VALUE;}

        /* Float Variable */
[0-9]+\.[0-9]+              {yylval.fval = atof(yytext); return FLOATING;}

        /* Char Variable */
\'.?\'                      {yylval.cval = (yytext[0]); return CHARACTER;}

        /* String Variable */
\".*\"                      {yylval.sval = (yytext); return STRING_LITERAL;}

    /* Colon and Semicolon */
[:;,]                        {return yytext[0];}

    /* Brackets */
[{}()\[\]]                   {return yytext[0];}

    /* Comments */
        /* Single Line Comments */
"//"[^\n]*                   {;}

        /* Multi Line Comments */
"/*"([^*]|\*[^\/])*"*/"      {;}

    /* Whitespace */
[ \t]+                     {;}

    /* New Line */
(\n)                         {yylineno = yylineno+1;}

    /* Error */
.                            {yyerror("Token not found");}

    /* Part 2 End */

%%

/* Part 3: Subroutines */

int yywrap(){
    return 1;
}

/* Part 3 End */