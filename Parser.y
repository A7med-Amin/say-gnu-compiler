/* Part 1: Defniitions */

%{
    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(char* s);
    int yylex(void);
%}

/* Part 1 End */

%%

/* Part 2: Action Rules */



/* Part 2 End */

%%

/* Part 3: Subroutines */

void yyerror(char* s){
    printf("\nERROR: %s\n", s);
    exit(1);
}

int main(){
    yyparse();
    return 0;
}

/* Part 3 End */