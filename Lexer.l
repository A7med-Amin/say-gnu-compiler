/* Part 1: Defniitions */

%{
    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>

    /* communications with yacc */
    #include "y.tab.h"
%}

/* Part 1 End */

%%

/* Part 2: Regex Rules */



/* Part 2 End */

%%

/* Part 3: Subroutines */

int yywrap(){
    return 1;
}

/* Part 3 End */