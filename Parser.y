/* Part 1: Definitions */

%{
    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>
    #include <cmath>  // Include the cmath header for pow function
    #include <string>

    #include "AssemblyGenerator.hpp"

    /* Header Files */
    #include "semantic_analyzer.hpp"

    /* Function prototypes */
    extern void yyerror(const char *s);
    int yylex(void);
    int yylineno;     /* from lexer represents line numbers */
    extern FILE *yyin;

    AssemblyGenerator assemblyGenerator;

    /* Macros */
    #ifndef TYPE_VALUE_MACROS_HPP
    #define TYPE_VALUE_MACROS_HPP
    #define GET_TYPE_VALUE(compareDataType, value1, value3, lhs, rhs)        \
        switch (compareDataType) {                                         \
        case INT_TYPE:                                                 \
            lhs = convertTypeValToEntry(INT_TYPE, value1.ival);        \
            rhs = convertTypeValToEntry(INT_TYPE, value3.ival);        \
            break;                                                     \
        case FLOAT_TYPE:                                               \
            lhs = convertTypeValToEntry(FLOAT_TYPE, value1.fval);      \
            rhs = convertTypeValToEntry(FLOAT_TYPE, value3.fval);      \
            break;                                                     \
        case STRING_TYPE:                                              \
            lhs = convertTypeValToEntry(STRING_TYPE, value1.sval);     \
            rhs = convertTypeValToEntry(STRING_TYPE, value3.sval);     \
            break;                                                     \
        case BOOL_TYPE:                                                \
            lhs = convertTypeValToEntry(BOOL_TYPE, value1.bval);       \
            rhs = convertTypeValToEntry(BOOL_TYPE, value3.bval);       \
            break;                                                     \
        case CHAR_TYPE:                                                \
            lhs = convertTypeValToEntry(CHAR_TYPE, value1.cval);       \
            rhs = convertTypeValToEntry(CHAR_TYPE, value3.cval);       \
            break;                                                     \
        }
    #endif // TYPE_VALUE_MACROS_HPP
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
/* %right ASSIGN POW
%nonassoc AND OR NOT
%left ADD SUB
%left MUL DIV MOD
%left EQ NEQ GT LT GTE LTE */

%left ADD SUB
%left MUL DIV MOD
%left AND OR
%nonassoc EQ NEQ GT LT GTE LTE
%nonassoc NOT
%right POW
%right ASSIGN

/* Part 1 End */

%%

/* Part 2: Patterns and Action Rules */

program:                                                                                    {printf("======== EMPTY PROGRAM ***********\n");}
        | codeBlock                                                                         {    
                                                                                                // printf("                 #_   _#\n");
                                                                                                // printf("                 |a` `a|\n");
                                                                                                // printf("                 |  u  |\n");
                                                                                                // printf("                 \\  =  /\n");
                                                                                                // printf("                 |\\___/|\n");
                                                                                                // printf("        ___ ____/:     :\\____ ___\n");
                                                                                                // printf("      .'   `.-===-\\   /-===-.`   '.\n");
                                                                                                // printf("     /      .-\"\"\"\"\"-.-\"\"\"\"\"-.      \\\n");
                                                                                                // printf("    /'             =:=             '\\\n");
                                                                                                // printf("  .'  ' .:    o   -=:=-   o    :. '  `.\n");
                                                                                                // printf("  (.'   /'. '-.....-'-.....-' .\\'   '.)\n");
                                                                                                // printf("  /' ._/   \".     --:--     .\"   \\_. '\\\n");
                                                                                                // printf(" |  .'|      \".  ---:---  .\"      |'.  |\n");
                                                                                                // printf(" |  : |       |  ---:---  |       | :  |\n");
                                                                                                // printf("  \\ : |       |_____._____|       | : /\n");
                                                                                                // printf("  /   (       |----|------|       )   \\\n");
                                                                                                // printf(" /... .|      |    |      |      |. ...\\\n");
                                                                                                // printf("|::::/'' jgs /     |       \\     ''\\::::|\n");
                                                                                                // printf("'\"\"\"\"       /'    .L_      `\\       \"\"\"\"'\n");
                                                                                                // printf("           /'-.,__/` `\\__..-'\\\n");
                                                                                                // printf("          ;      /     \\      ;\n");
                                                                                                // printf("          :     /       \\     |\n");
                                                                                                // printf("          |    /         \\.   |\n");
                                                                                                // printf("          |`../           |  ,/\n");
                                                                                                // printf("          ( _ )           |  _)\n");
                                                                                                // printf("          |   |           |   |\n");
                                                                                                // printf("          |___|           \\___|\n");
                                                                                                // printf("          :===|            |==|\n");
                                                                                                // printf("           \\  /            |__|\n");
                                                                                                // printf("           /\\/\\           /\"\"\"`8.__\n");
                                                                                                // printf("           |oo|           \\__.//___)\n");
                                                                                                // printf("           |==|\n");
                                                                                                // printf("           \\__/\n");
                                                                                                printf("                       SALAMO ALEEKO! ")
                                                                                            }
        ;

codeBlock: codeStatement                                            
        |  codeBlock codeStatement                                  
        ;

codeStatement: variableDeclaration                                                                  
        | constantDeclaration                                                                  
        | assignment                                                                          
        | WHILE '(' expression 
        {
            if ($3.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        }
        ')' scopeBlock        
        | REPEAT scopeBlock UNTIL '(' expression 
        {
            if ($5.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        }
        ')' ';'                                     
        | FOR '(' {createNewSymbolTable();} forLoopInitialization expression
        {
            if ($5.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of FOR must be boolean", yylineno);
                return 0;
            }
        }
        forLoopItter ')' loopsScopeBlock           
        | ifCondition                                                                       
        | SWITCH '(' IDENTIFIER 
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($3);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE && newEntry->getTypeValue()->type != CHAR_TYPE){
                writeSemanticError("Switch identifier must be char type or integer", yylineno);
                return 0;
            }
        }
        ')' switchBlock                                             
        | scopeBlock
        | PRINT '(' printStatement ')' ';'                                                 
        | function 
        | voidFunctionCall ';'
        | error               { yyerror("Unexpected statement"); }
        ;

/* Data Types and Data Values */
dataType: INT_DATA_TYPE | FLOAT_DATA_TYPE| CHAR_DATA_TYPE | STRING_DATA_TYPE | BOOLEAN_DATA_TYPE ;

dataValue: expression | STRING_LITERAL | CHARACTER;

constantValue: INTEGER_VALUE | FLOATING | CHARACTER | STRING_LITERAL | BOOLEAN_TRUE | BOOLEAN_FALSE ;

/* Code Expressions */
expression: arithmetic | boolean ;

boolean: BOOLEAN_TRUE | BOOLEAN_FALSE 
        | expression EQ arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityEqual(lhs, rhs);
        }
        | expression NEQ arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityNot(lhs, rhs);
        }
        | expression GT arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityGT(lhs, rhs);
        }
        | expression LT arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityLT(lhs, rhs);
        }
        | expression GTE arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityGTE(lhs, rhs);
        }
        | expression LTE arithmetic 
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (typeMismatch(lhsType, rhsType))
            {
                writeSemanticError("Type mismatch", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            $$.bval = checkEqualityLTE(lhs, rhs);
        }
        | NOT expression 
        {
            int varType = $2.type;
            if (varType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with NOT operation", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            $$.bval = !$2.bval;
        }
        | expression AND expression
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with AND operation, types must be boolean", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            $$.bval = $1.bval && $3.bval;
        }
        | expression OR expression
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (lhsType != BOOL_TYPE || rhsType != BOOL_TYPE)
            {
                writeSemanticError("Type mismatch with OR operation, types must be boolean", yylineno);
                return 0;
            }
            $$.type = BOOL_TYPE;
            $$.bval = $1.bval || $3.bval;
        }
        ; 

arithmetic: IDENTIFIER INC                                        
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot increment constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with INC operation, types must be integer", yylineno);
                return 0;
            }
            $$.type = INT_TYPE;
            $$.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = $$.ival;
        }
        | IDENTIFIER DEC                                        
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot decrement constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with DEC operation, types must be integer", yylineno);
                return 0;
            }
            $$.type = INT_TYPE;
            $$.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = $$.ival;
        }
        | INC IDENTIFIER                                        
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($2);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot increment constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with INC operation, types must be integer", yylineno);
                return 0;
            }
            $$.type = INT_TYPE;
            $$.ival = newEntry->getTypeValue()->value.ival + 1;
            newEntry->getTypeValue()->value.ival = $$.ival;
        }
        | DEC IDENTIFIER                                        
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($2);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot decrement constant variable", yylineno);
                return 0;
            }
            if(newEntry->getTypeValue()->type != INT_TYPE){
                writeSemanticError("Type mismatch with DEC operation, types must be integer", yylineno);
                return 0;
            }
            $$.type = INT_TYPE;
            $$.ival = newEntry->getTypeValue()->value.ival - 1;
            newEntry->getTypeValue()->value.ival = $$.ival;
        }
        | complexArithmetic
        ;

complexArithmetic: complexArithmetic ADD minorTerm       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with ADD operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        $$.type = FLOAT_TYPE;
                        $$.fval = lhs->value.ival + rhs->value.fval;
                    }
                    else
                    {
                        $$.type = INT_TYPE;
                        $$.ival = lhs->value.ival + rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        $$.fval = lhs->value.fval + rhs->value.ival;
                    }
                    else
                    {
                        $$.fval = lhs->value.fval + rhs->value.fval;
                    }
                    break;
            }
        }
        | complexArithmetic SUB minorTerm       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with SUB operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        $$.type = FLOAT_TYPE;
                        $$.fval = lhs->value.ival - rhs->value.fval;
                    }
                    else
                    {
                        $$.type = INT_TYPE;
                        $$.ival = lhs->value.ival - rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        $$.fval = lhs->value.fval - rhs->value.ival;
                    }
                    else
                    {
                        $$.fval = lhs->value.fval - rhs->value.fval;
                    }
                    break;
            }
        }
        | minorTerm
        ;

minorTerm: minorTerm MUL majorTerm       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with MUL operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        $$.type = FLOAT_TYPE;
                        $$.fval = lhs->value.ival * rhs->value.fval;
                    }
                    else
                    {
                        $$.type = INT_TYPE;
                        $$.ival = lhs->value.ival * rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        $$.fval = lhs->value.fval * rhs->value.ival;
                    }
                    else
                    {
                        $$.fval = lhs->value.fval * rhs->value.fval;
                    }
                    break;
            }
        }
        | minorTerm DIV majorTerm       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with DIV operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        $$.type = FLOAT_TYPE;
                        $$.fval = lhs->value.ival / rhs->value.fval;
                    }
                    else
                    {
                        $$.type = INT_TYPE;
                        $$.ival = lhs->value.ival / rhs->value.ival;
                    }
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        $$.fval = lhs->value.fval / rhs->value.ival;
                    }
                    else
                    {
                        $$.fval = lhs->value.fval / rhs->value.fval;
                    }
                    break;
            }
        }
        | minorTerm MOD majorTerm       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if (lhsType != INT_TYPE || rhsType != INT_TYPE)
            {
                writeSemanticError("Type mismatch with MOD operation, must be integers", yylineno);
                return 0;
            }
            $$.type = INT_TYPE;
            $$.ival = $1.ival % $3.ival;
        }
        | majorTerm
        ;

majorTerm: majorTerm POW instance       
        {
            int lhsType = $1.type;
            int rhsType = $3.type;
            if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
            {
                writeSemanticError("Type mismatch with POW operation, must be integers or float", yylineno);
                return 0;
            }
            TypeValue * lhs;
            TypeValue * rhs;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);
            switch(lhsType){
                case INT_TYPE:
                    if (rhsType == FLOAT_TYPE)
                    {
                        $$.type = FLOAT_TYPE;
                        $$.fval = pow(lhs->value.ival, rhs->value.fval);
                    }
                    else
                    {
                        $$.type = INT_TYPE;
                        $$.ival = pow(lhs->value.ival, rhs->value.ival);
                    }
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    if (rhsType == INT_TYPE)
                    {
                        $$.fval = pow(lhs->value.fval, rhs->value.ival);
                    }
                    else
                    {
                        $$.fval = pow(lhs->value.fval, rhs->value.fval);
                    }
                    break;
            }
        }
        | instance
        ;

instance: INTEGER_VALUE | FLOATING | functionCall
        | IDENTIFIER 
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(!newEntry->getinitialization())
            {
                writeSemanticError("Variable not initialized", yylineno);
                return 0;
            }
            newEntry->setused(true);
            $$.type = (int)newEntry->getTypeValue()->type;
            switch($$.type){
                case INT_TYPE:
                    $$.ival = newEntry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    $$.fval = newEntry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    $$.sval = newEntry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    $$.bval = newEntry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    $$.cval = newEntry->getTypeValue()->value.cval;
                    break;
            }
        }
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
            string valueStr;
            switch(idTypeValue->type){
                case INT_TYPE:
                    idTypeValue->value.ival = $4.ival;
                    valueStr = to_string($4.ival);
                    break;
                case FLOAT_TYPE:
                    idTypeValue->value.fval = $4.fval;
                    valueStr = to_string($4.fval);
                    break;
                case STRING_TYPE:
                    idTypeValue->value.sval = $4.sval;
                    valueStr = $4.sval;
                    break;
                case BOOL_TYPE:
                    idTypeValue->value.bval = $4.bval;
                    valueStr = to_string($4.bval);
                    break;
                case CHAR_TYPE:
                    idTypeValue->value.cval = $4.cval;
                    valueStr = to_string($4.cval);
                    break;
            }
            addEntryToCurrentTable($2, VAR, idTypeValue, true);

            const char* name = assemblyGenerator.addAssignment(newEntry);
            // const char* name = generator.addTemp($1.value , "" , "");
            assemblyGenerator.addQuad("ALLOC",$2,"",name);
            assemblyGenerator.addQuad("ASSIGN",valueStr,"",name);
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
ifCondition: IF '(' expression
        {
            if ($3.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of IF must be boolean", yylineno);
                return 0;
            }
        }
        ')' scopeBlock
        elseIfCondition elseStmnt
        ;

elseIfCondition: elseIfCondition ELSE IF '(' expression
        {
            if ($5.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of ELSE IF must be boolean", yylineno);
                return 0;
            }
        }
        ')' scopeBlock
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

function :  dataType IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock RETURN  dataValue ';' {scopeEnd();} '}'  {}
        |  dataType IDENTIFIER '(' {createNewSymbolTable();} ')' '{' codeBlock RETURN  dataValue ';' {scopeEnd();} '}'           {}
        |   VOID_TYPE IDENTIFIER '(' {createNewSymbolTable();} argList ')' '{' codeBlock returnCase {scopeEnd();} '}'             {}
        |   VOID_TYPE IDENTIFIER '(' {createNewSymbolTable();} ')' '{' codeBlock returnCase {scopeEnd();} '}'             {}
        ;

returnCase: RETURN ';'    		                                                                {}	 
        |                                                                                       {}	 
        ;

functionCall: IDENTIFIER '(' callList ')'   		                                            {}
        | IDENTIFIER '(' ')'   		                                                            {}
        ;

voidFunctionCall: IDENTIFIER '(' callList ')'   		                                        {}
        | IDENTIFIER '(' ')'   		                                                            {}
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
        {
            printf("========  PRINT SUCCESSFUL ***********\n");
        }                      
        | dataValue                                          
        ;  

/* Part 2 End */

%%

/* Part 3: Subroutines */

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