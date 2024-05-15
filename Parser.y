/* Part 1: Definitions */

%{
    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>
    #include "AssemblyGenerator.hpp"

    /* Header Files */
    #include "semantic_analyzer.hpp"

    /* Function prototypes */
    void yyerror(const char* s);
    int yylex(void);
    int yylineno;     /* from lexer represents line numbers */
    extern FILE *yyin;

    AssemblyGenerator assemblyGenerator;
%}

%union{
    int lexType;
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
%type <actualValue> functionCall
%type <actualValue> dataValue
%type <actualValue> constantValue
%type <actualValue> expression
%type <actualValue> boolean
%type <actualValue> arithmetic
%type <actualValue> complexArithmetic
%type <actualValue> minorTerm
%type <actualValue> majorTerm
%type <actualValue> instance
%type <actualValue> printStatement
%type <actualValue> callSingleParam
%type <actualValue> callList
%type <actualValue> switchValidValue


/* Data Types */
%type <lexType> dataType
%token <lexType> INT_DATA_TYPE 
%token <lexType> FLOAT_DATA_TYPE 
%token <lexType> CHAR_DATA_TYPE 
%token <lexType> STRING_DATA_TYPE 
%token <lexType> BOOLEAN_DATA_TYPE 

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

codeBlock: codeStatement                                            {}
        |  codeBlock codeStatement                                  {}
        ;


codeStatement: variableDeclaration                                                                  
        | constantDeclaration                                                                  
        | assignment                                                                          
        | WHILE '(' expression ')' scopeBlock        
        | REPEAT scopeBlock UNTIL '(' expression ')' ';'                                     
        | FOR '(' {createNewSymbolTable();} forLoopInitialization expression forLoopItter ')' loopsScopeBlock           
        | ifCondition                                                                       
        | SWITCH '(' IDENTIFIER ')' switchBlock                                             
        | scopeBlock
        | PRINT '(' printStatement ')' ';'                                                 
        | function 
        | voidFunctionCall ';'
        | error               { yyerror("Unexpected statement."); }
        ;

/* Data Types and Data Values */
dataType: INT_DATA_TYPE | FLOAT_DATA_TYPE| CHAR_DATA_TYPE | STRING_DATA_TYPE | BOOLEAN_DATA_TYPE ;

dataValue: expression | STRING_LITERAL | CHARACTER;

constantValue: INTEGER_VALUE | FLOATING | CHARACTER | STRING_LITERAL | BOOLEAN_TRUE | BOOLEAN_FALSE ;

/* Code Expressions */
expression: arithmetic | boolean ;

boolean: BOOLEAN_TRUE | BOOLEAN_FALSE 
        | expression EQ arithmetic 
        {printGray("========  EQUAL OPERATION ***********");}
        | expression NEQ arithmetic 
        {printGray("========  NOT EQUAL OPERATION ***********");}
        | expression GT arithmetic 
        {printGray("========  GREATER THAN OPERATION ***********");}
        | expression LT arithmetic 
        {printGray("========  LESS THAN OPERATION ***********");}
        | expression GTE arithmetic 
        {printGray("========  GREATER THAN OR EQUAL OPERATION ***********");}
        | expression LTE arithmetic 
        {printGray("========  LESS THAN OR EQUAL OPERATION ***********");}
        | NOT expression 
        {printGray("========  NOT OPERATION ***********");}
        | expression AND arithmetic
        {printGray("========  AND OPERATION ***********");}
        | expression AND NOT arithmetic
        {printGray("========  AND NOT OPERATION ***********");}
        | expression OR arithmetic
        {printGray("========  OR OPERATION ***********");}
        | expression OR NOT arithmetic
        {printGray("========  OR NOT OPERATION ***********");}
        ; 

arithmetic: IDENTIFIER INC                                        
        {printMagenta("========  INCREMENT ***********");}
        | IDENTIFIER DEC                                        
        {printMagenta("========  DECREMENT ***********");}
        | INC IDENTIFIER                                        
        {printMagenta("========  INCREMENT ***********");}
        | DEC IDENTIFIER                                        
        {printMagenta("========  DECREMENT ***********");}
        | complexArithmetic
        {printMagenta("========  COMPLEX ARITHMETIC OPERATION ***********");}
        ;

complexArithmetic: complexArithmetic ADD minorTerm       
        {printMagenta("========  ADDITION OPERATION ***********");}
        | complexArithmetic SUB minorTerm       
        {printMagenta("========  SUBTRACTION OPERATION ***********");}
        | minorTerm
        ;

minorTerm: minorTerm MUL majorTerm       
        {printMagenta("========  MULTIPLICATION OPERATION ***********");}
        | minorTerm DIV majorTerm       
        {printMagenta("========  DIVISION OPERATION ***********");}
        | minorTerm MOD majorTerm       
        {printMagenta("========  MODULUS OPERATION ***********");}
        | majorTerm
        ;

majorTerm: majorTerm POW instance       
        {printMagenta("========  POWER OPERATION ***********");}
        | instance
        ;

instance: INTEGER_VALUE | FLOATING | functionCall
        | IDENTIFIER 
        {printMagenta("========  IDENTIFIER ***********");}
        | '(' expression ')' {$$ = $2;}
        ;

/* Declaration and Assignment */
assignment: IDENTIFIER ASSIGN dataValue ';' 
        {
            // Check if the variable has been declared before
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            // If the variable has not been declared before, throw an error
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            // Check if the variable is a constant
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot assign value to constant", yylineno);
                return 0;
            }
            // Check on type mismatch
            int idType = (int)newEntry->getTypeValue()->type;
            int valType = $3.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Assignment type mismatch", yylineno);
                return 0;
            }
            // Assign the value to the variable (update the symbol table entry)
            switch(idType){
                case INT_TYPE:
                    newEntry->getTypeValue()->value.ival = $3.ival;
                    break;
                case FLOAT_TYPE:
                    newEntry->getTypeValue()->value.fval = $3.fval;
                    break;
                case STRING_TYPE:
                    newEntry->getTypeValue()->value.sval = $3.sval;
                    break;
                case BOOL_TYPE:
                    newEntry->getTypeValue()->value.bval = $3.bval;
                    break;
                case CHAR_TYPE:
                    newEntry->getTypeValue()->value.cval = $3.cval;
                    break;
            }
            newEntry->setinitialization(true);
        }
        ;

variableDeclaration: dataType IDENTIFIER ';' 
        {
            // Check if the variable has been declared before
            SymbolTableEntry* newEntry = identifierScopeCheck($2);
            // If the variable has been declared before, throw an error
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            // Create a new entry for the variable to symbol table
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>($1);
            addEntryToCurrentTable($2, VAR, idTypeValue, false);
            const char* name = assemblyGenerator.addAssignment(newEntry);
            assemblyGenerator.addQuad("ALLOC",$2,"",name);


        }
        | variableDeclarationWithAssignment
        ;

variableDeclarationWithAssignment: dataType IDENTIFIER ASSIGN dataValue ';'
        {
            // Check if the variable has been declared before
            SymbolTableEntry* newEntry = identifierScopeCheck($2);
            // If the variable has been declared before, throw an error
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            // Check on type mismatch
            int idType = $1;
            int valType = $4.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
            // Create a new entry for the variable to symbol table
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(idType);
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = $4.ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = $4.fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = $4.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = $4.bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = $4.cval;
                    break;
            }
            addEntryToCurrentTable($2, VAR, idTypeValue, true);
        }
        ;

constantDeclaration: CONSTANT dataType IDENTIFIER ASSIGN constantValue ';'
        {
            // Check if the variable has been declared before
            SymbolTableEntry* newEntry = identifierScopeCheck($3);
            // If the variable has been declared before, throw an error
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            // Check on type mismatch
            int idType = $2;
            int valType = $5.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
            // Create a new entry for the variable to symbol table
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>(idType);
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = $5.ival;
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = $5.fval;
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = $5.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = $5.bval;
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = $5.cval;
                    break;
            }
            addEntryToCurrentTable($3, CONST, idTypeValue, true);
        }
        ;   

/* Conditional statements */
ifCondition: IF '(' expression ')' scopeBlock
        {printf("========  IF STATEMENT ***********\n");}
        elseIfCondition elseStmnt
        ;

elseIfCondition: elseIfCondition ELSE IF '(' expression ')' scopeBlock
        |
        ;

elseStmnt: ELSE scopeBlock
        |
        ;

/* Switch Case */
switchBlock: '{' {createNewSymbolTable();} caseExpression {scopeEnd();} '}'                     
    ;


caseExpression:	
            caseDefault 	                   
    |       CASE switchValidValue ':' codeBlock BREAK ';' caseExpression  
    {printf("========  CASE STATEMENT ***********\n");}
	;

switchValidValue: INTEGER_VALUE | CHARACTER 
        ;

caseDefault:
            DEFAULT ':' codeBlock BREAK ';'    		            	 
            | DEFAULT ':' codeBlock    		                    	 
            |                                                       	 
    ;

/* Loops and Scope */
forLoopInitialization: assignment   
        | variableDeclarationWithAssignment 
        | ';'                        
        ;

forLoopItter: ';' IDENTIFIER ASSIGN expression
        | ';' expression
        | ';'
        ;

scopeBlock: '{' {createNewSymbolTable();} codeBlock {scopeEnd();} '}'                                             
    ;

loopsScopeBlock: '{' codeBlock {scopeEnd();} '}'                                                                  
    ;

/////////////////////////////// Function ///////////////////////////////

function :  dataType IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock RETURN  dataValue ';' {scopeEnd();} '}'  {printf("========  FUNCTION ***********\n");}
        |  dataType IDENTIFIER '(' {createNewSymbolTable();} ')' '{' codeBlock RETURN  dataValue ';' {scopeEnd();} '}'           {printf("========  FUNCTION ***********\n");}
        |   VOID_TYPE IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock returnCase {scopeEnd();} '}'             {printf("========  VOID FUNCTION ***********\n");}
        |   VOID_TYPE IDENTIFIER '(' {createNewSymbolTable();} ')' '{' codeBlock returnCase {scopeEnd();} '}'             {printf("========  VOID FUNCTION ***********\n");}
        ;

returnCase: RETURN ';'    		                                                                {printf("========  VOID FUNCTION RETURN ***********\n");}	 
        |                                                                                       {printf("========  NO VOID FUNCTION RETURN ***********\n");}	 
        ;

functionCall: IDENTIFIER '(' callList ')'   		                                            {printf("========  FUNCTION CALL ***********\n");}
        | IDENTIFIER '(' ')'   		                                                            {printf("========  FUNCTION CALL ***********\n");}
        ;

voidFunctionCall: IDENTIFIER '(' callList ')'   		                                            {printf("========  FUNCTION CALL ***********\n");}
        | IDENTIFIER '(' ')'   		                                                            {printf("========  FUNCTION CALL ***********\n");}
        ;

callList:  callSingleParam ',' callList 
	    |  callSingleParam  
	    ;

callSingleParam: dataValue
        | functionCall              
        ;

argList:  arg ',' argList 
	    | arg                           
	    ;

arg: dataType IDENTIFIER 		      
        {}
        | dataType IDENTIFIER ASSIGN constantValue 
        {}  
        ;

/* Print Statement */
printStatement: dataValue ',' printStatement                        
        | dataValue                                          
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
    

    yyparse();
	printf("\nParsing complete\n");

    if (argc > 1) {
        fclose(file);
    }

    saveSymbolTables();

    const char* quadPath = "quad.txt";
    const char* assemblyPath = "assembly.txt";

    FILE* quadFile = fopen(quadPath, "w");
    FILE* assemblyFile = fopen(assemblyPath, "w");

    assemblyGenerator.printQuadsToFile();


    return 0;
}

/* Part 3 End */