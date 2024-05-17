/* Part 1: Definitions */

%{
    #define register

    /* C libraries */
    #include <stdio.h>
    #include <stdlib.h>
    #include <cmath>  // Include the cmath header for pow function
    #include <string>
    #include <cstring>  // For strdup
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

    char* concatenateNames(const char* name1, const char* name2, const char* name3) {
    std::string nameRepStr = std::string(name1) + std::string(name2) + std::string(name3);
    return strdup(nameRepStr.c_str());  // Copy the result back to a char*
    }
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
%type <actualValue> TypedFunctionCall
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
%type <actualValue> CallList 
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
                                                                                                // printf("                       SALAMO ALEEKO! ")
                                                                                            }
        ;

codeBlock: codeStatement                                            
        |  codeBlock codeStatement                                  
        ;

codeStatement: variableDeclaration                                                                  
        | constantDeclaration                                                                  
        | assignment ';'                                                                         
        | WHILE '(' expression 
        {
            if ($3.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of WHILE must be boolean", yylineno);
                return 0;
            }
        }
        ')' scopeBlock { assemblyGenerator.endScope(whileScope);}     
        | 
        REPEAT 
        scopeBlock 
        UNTIL '(' expression 
        {
            assemblyGenerator.endScope(repeatScope);
            if ($5.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of REPEAT must be boolean", yylineno);
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
        forLoopItter ')' loopsScopeBlock { printf("for loop itter\n");
            assemblyGenerator.endScope(forScope);}           
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
        ')' switchBlock { assemblyGenerator.endScope(switchScope); }                                              
        | scopeBlock
        | PRINT '(' printStatement ')' ';'                                                 
        | function 
        | VoidFunctionCall ';'
        | ReturnCase 
        | error               { yyerror("Unexpected statement"); }
        ;

/* Data Types and Data Values */
dataType: INT_DATA_TYPE | FLOAT_DATA_TYPE| CHAR_DATA_TYPE | STRING_DATA_TYPE | BOOLEAN_DATA_TYPE ;

dataValue: expression
| STRING_LITERAL 
{
    { 
        string valueStr = $1.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
        } 
}
| CHARACTER {
    { 
        char charValue = static_cast<char>($1.cval);  
        string valueStr(1, charValue);  
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
        } 
} 
;

constantValue: INTEGER_VALUE 
{
    string valueStr = to_string($1.ival);
    const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
    assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
    // $$.nameRep = strdup(valueStr.c_str());
}
| FLOATING 
{ 
        string valueStr = to_string($1.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
} 
| CHARACTER 
{ 
        string valueStr = to_string($1.cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
} 
| STRING_LITERAL 
{ 
        string valueStr = $1.sval;
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
} 
| BOOLEAN_TRUE 
{ 
        string valueStr = "true";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
} 
| BOOLEAN_FALSE
{ 
        string valueStr = "false";
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
}  
;

/* Code Expressions */
expression: arithmetic | boolean ;

boolean: BOOLEAN_TRUE
        {
            cout << "BOOLEAN_TRUE\n";
            const char* name = assemblyGenerator.addTempVariable("true" , "" , "");
            assemblyGenerator.addQuadruple("ASSIGN", "TRUE", "", name);
            $$.nameRep = strdup("true");
        }
        | BOOLEAN_FALSE 
        {
        const char* name = assemblyGenerator.addTempVariable("false" , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", "FALSE", "", name);
        $$.nameRep = strdup("false");
        }
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
            string valueStr = $$.bval ? "true" : "false";

           // Print debugging information
            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            // Allocate memory for the final value string and assign it to nameRep
            $$.nameRep = strdup(valueStr.c_str());

            // Add the quadruple for the EQ operation
            assemblyGenerator.addQuadruple("EQU", name1, name2, name);
        }
        | expression NEQ arithmetic 
        {
          int lhsType = $1.type;
    int rhsType = $3.type;

    // Check for type mismatch
    if (typeMismatch(lhsType, rhsType))
    {
        writeSemanticError("Type mismatch", yylineno);
        return 0;
    }

    // Set the result type to BOOL_TYPE
    $$.type = BOOL_TYPE;

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

    // Check for inequality
    $$.bval = checkEqualityNot(lhs, rhs);

    // Convert the boolean result to a string
    string valueStr = $$.bval ? "true" : "false";

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    $$.nameRep = strdup(valueStr.c_str());

    // Add the quadruple for the NEQ operation
    assemblyGenerator.addQuadruple("NEQ", name1, name2, name);
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

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

            $$.bval = checkEqualityGT(lhs, rhs);

            string valueStr = $$.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GT", name1, name2, name);
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

            string valueStr = $$.bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LT", name1, name2, name);
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

            TypeValue *lhs;
            TypeValue *rhs;

            EntryType compareDataType = static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

            $$.bval = checkEqualityGTE(lhs, rhs);

            string valueStr = $$.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("GTE", name1, name2, name);
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

            string valueStr = $$.bval ? "true" : "false";

           printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("LTE", name1, name2, name);
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

   string valueStr = $$.bval ? "true" : "false";

            printf("varStr1NameRep: %s \n", $2.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($2.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name: %s\n", name1, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("NOT", name1, "", name);

            
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

            string valueStr = $$.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("AND", name1, name2, name);
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

            string valueStr = $$.bval ? "true" : "false";

            printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
            const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
            const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
            const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
            printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

            $$.nameRep = strdup(valueStr.c_str());

            assemblyGenerator.addQuadruple("OR", name1, name2, name);
        }
        ; 

arithmetic: IDENTIFIER INC                                        
        {
            printf("INC\n");
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
            newEntry->getTypeValue()->value.ival = $$.ival;\

            string varStr1NameRep = $$.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "++" , "");
            $$.nameRep = concatenateNames(name1, "++" , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
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

            string varStr1NameRep = $$.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable(name1, "--" , "");
            $$.nameRep = concatenateNames(name1, "--" , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
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

            string varStr1NameRep = $$.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("++", name1 , "");
            $$.nameRep = concatenateNames("++", name1 , "");
            assemblyGenerator.addQuadruple("INC", name1, "", name);
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

            string varStr1NameRep = $$.nameRep;
            const char* name1 = assemblyGenerator.getTempVariable(varStr1NameRep);
            const char* name = assemblyGenerator.addTempVariable("--", name1 , "");
            $$.nameRep = concatenateNames("--", name1 , "");
            assemblyGenerator.addQuadruple("DEC", name1, "", name);
        }
        | complexArithmetic
        ;

complexArithmetic: complexArithmetic ADD minorTerm       
        {
            cout << " ------------- ADD -------------" << endl;
        int lhsType = $1.type;
        int rhsType = $3.type;

        if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
        {
            writeSemanticError("Type mismatch with ADD operation, must be integers or float", yylineno);
            return 0;
        }

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            $$.type = FLOAT_TYPE;
            $$.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) + 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << $$.fval << endl;
        }
        else
        {
            $$.type = INT_TYPE;
            $$.ival = lhs->value.ival + rhs->value.ival;
            cout << "value: " << $$.ival << endl;
        }

        stringstream valueStream;
        if ($$.type == FLOAT_TYPE)
        {
            valueStream << $$.fval;
        }
        else
        {
            valueStream << $$.ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
        const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        $$.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("ADD", name1, name2, name);
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

        TypeValue *lhs;
        TypeValue *rhs;
        EntryType compareDataType = static_cast<EntryType>(lhsType);
        GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

        if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
        {
            $$.type = FLOAT_TYPE;
            $$.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) - 
                    (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
            cout << "value: " << $$.fval << endl;
        }
        else
        {
            $$.type = INT_TYPE;
            $$.ival = lhs->value.ival - rhs->value.ival;
            cout << "value: " << $$.ival << endl;
        }

        stringstream valueStream;
        if ($$.type == FLOAT_TYPE)
        {
            valueStream << $$.fval;
        }
        else
        {
            valueStream << $$.ival;
        }
        string valueStr = valueStream.str();

        printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
        const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
        const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
        const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
        printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

        $$.nameRep = strdup(valueStr.c_str());

        assemblyGenerator.addQuadruple("SUB", name1, name2, name);
        }
        | minorTerm
        ;

minorTerm: minorTerm MUL majorTerm       
        {
int lhsType = $1.type;
    int rhsType = $3.type;

    // Ensure types are either INT_TYPE or FLOAT_TYPE
    if ((lhsType != INT_TYPE && lhsType != FLOAT_TYPE) || (rhsType != INT_TYPE && rhsType != FLOAT_TYPE))
    {
        writeSemanticError("Type mismatch with MUL operation, must be integers or float", yylineno);
        return 0;
    }

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

    // Calculate the final value based on the types
    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        $$.type = FLOAT_TYPE;
        $$.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) * 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << $$.fval << endl;
    }
    else
    {
        $$.type = INT_TYPE;
        $$.ival = lhs->value.ival * rhs->value.ival;
        cout << "value: " << $$.ival << endl;
    }

    // Convert the final value to a string
    stringstream valueStream;
    if ($$.type == FLOAT_TYPE)
    {
        valueStream << $$.fval;
    }
    else
    {
        valueStream << $$.ival;
    }
    string valueStr = valueStream.str();

    // Print debugging information
    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    // Allocate memory for the final value string and assign it to nameRep
    $$.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MUL", name1, name2, name);
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

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        $$.type = FLOAT_TYPE;
        $$.fval = (lhsType == INT_TYPE ? lhs->value.ival : lhs->value.fval) / 
                  (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval);
        cout << "value: " << $$.fval << endl;
    }
    else
    {
        $$.type = INT_TYPE;
        $$.ival = lhs->value.ival / rhs->value.ival;
        cout << "value: " << $$.ival << endl;
    }

    stringstream valueStream;
    if ($$.type == FLOAT_TYPE)
    {
        valueStream << $$.fval;
    }
    else
    {
        valueStream << $$.ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    $$.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("DIV", name1, name2, name);
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
    cout << "value: " << $$.ival << endl;

    stringstream valueStream;
    valueStream << $$.ival;
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    $$.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("MOD", name1, name2, name);
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

    TypeValue *lhs;
    TypeValue *rhs;
    EntryType compareDataType = static_cast<EntryType>(lhsType);
    GET_TYPE_VALUE(compareDataType, $1, $3, lhs, rhs);

    if (lhsType == FLOAT_TYPE || rhsType == FLOAT_TYPE)
    {
        $$.type = FLOAT_TYPE;
        $$.fval = (lhsType == INT_TYPE ? pow(lhs->value.ival, rhs->value.fval) : pow(lhs->value.fval, (rhsType == INT_TYPE ? rhs->value.ival : rhs->value.fval)));
        cout << "value: " << $$.fval << endl;
    }
    else
    {
        $$.type = INT_TYPE;
        $$.ival = pow(lhs->value.ival, rhs->value.ival);
        cout << "value: " << $$.ival << endl;
    }

    stringstream valueStream;
    if ($$.type == FLOAT_TYPE)
    {
        valueStream << $$.fval;
    }
    else
    {
        valueStream << $$.ival;
    }
    string valueStr = valueStream.str();

    printf("varStr1NameRep: %s, varStr2NameRep: %s \n", $1.nameRep, $3.nameRep);
    const char* name1 = assemblyGenerator.getTempVariable($1.nameRep);
    const char* name2 = assemblyGenerator.getTempVariable($3.nameRep);
    const char* name = assemblyGenerator.addTempVariable(valueStr, "", "");
    printf("name1: %s, name2: %s, name: %s\n", name1, name2, name);

    $$.nameRep = strdup(valueStr.c_str());

    assemblyGenerator.addQuadruple("POW", name1, name2, name);
        }
        | instance 
        ;

instance: INTEGER_VALUE 
        { 
        // printf("Integer: %d\n", $1.ival);
        string valueStr = to_string($1.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
        } 
        | FLOATING  
        { 
        string valueStr = to_string($1.fval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
        } 
        | TypedFunctionCall
        | IDENTIFIER 
        {
            cout << "Identifier: " << $1 << endl;
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            const char* nameeReg = assemblyGenerator.getRegisterAssignment(newEntry);
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
            string valueStr;
            switch($$.type){
                case INT_TYPE:
                    $$.ival = newEntry->getTypeValue()->value.ival;
                    valueStr = to_string($$.ival);
                    cout << "Value string: " << valueStr << endl;
                    $$.nameRep = strdup(valueStr.c_str());
                    break;
                case FLOAT_TYPE:
                    $$.fval = newEntry->getTypeValue()->value.fval;
                    valueStr = to_string($$.fval);
                    $$.nameRep = strdup(valueStr.c_str());
                    break;
                case STRING_TYPE:
                    $$.sval = newEntry->getTypeValue()->value.sval;
                    valueStr = $$.sval;
                    $$.nameRep = strdup(valueStr.c_str());
                    break;
                case BOOL_TYPE:
                    $$.bval = newEntry->getTypeValue()->value.bval;
                    valueStr = to_string($$.bval);
                    if($$.bval)
                    {
                        valueStr = "true";
                    }
                    else
                    {
                        valueStr = "false";
                    }
                    cout << "Value string: " << valueStr << endl;
                    $$.nameRep = strdup(valueStr.c_str());
              

                    
                    break;
                case CHAR_TYPE:
                    $$.cval = newEntry->getTypeValue()->value.cval;
                    valueStr = to_string($$.cval);
                    $$.nameRep = strdup(valueStr.c_str());
                    break;
            }
        }
        | '(' expression ')' {$$ = $2;}
        | SUB expression     
        {
            TypeValue * lhs;
            int lhsType = $2.type;
            EntryType compareDataType= static_cast<EntryType>(lhsType);
            GET_TYPE_VALUE(compareDataType, $2, $2, lhs, lhs);
            switch(lhsType){
                case INT_TYPE:
                    $2.ival = -static_cast<int>(lhs->value.ival);
                    break;
                case FLOAT_TYPE:
                    $2.fval = -static_cast<float>(lhs->value.fval);
                    break;
            }
            $$ = $2;
        }
        ;

/* Declaration and Assignment */
assignment: IDENTIFIER ASSIGN dataValue 
        {
            SymbolTableEntry* newEntry = getIdentifierEntry($1);
            if(newEntry == nullptr){
                writeSemanticError("Using variable not declared", yylineno);
                return 0;
            }
            if(newEntry->getKind() == CONST){
                writeSemanticError("Cannot assign value to constant", yylineno);
                return 0;
            }
            int idType = (int)newEntry->getTypeValue()->type;
            int valType = $3.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Assignment type mismatch", yylineno);
                return 0;
            }
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
            newEntry->setused(true);

            const char* name = assemblyGenerator.getRegisterAssignment(newEntry);
            const char* VarName = assemblyGenerator.getTempVariable($3.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        }
        ;

variableDeclaration: dataType IDENTIFIER ';' 
        {
            SymbolTableEntry* newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>($1);
            SymbolTableEntry * entry = addEntryToCurrentTable($2, VAR, idTypeValue, false);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",$2,"",name);


        }
        | variableDeclarationWithAssignment
        ;

variableDeclarationWithAssignment: dataType IDENTIFIER ASSIGN dataValue ';'
        {
            SymbolTableEntry* newEntry = identifierScopeCheck($2);

            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = $1;
            int valType = $4.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
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
            SymbolTableEntry * entry = addEntryToCurrentTable($2, VAR, idTypeValue, true);


            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",$2,"",name);
            const char* VarName = assemblyGenerator.getTempVariable($4.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);


        }
        ;

constantDeclaration: CONSTANT dataType IDENTIFIER ASSIGN constantValue ';'
        {
            SymbolTableEntry* newEntry = identifierScopeCheck($3);
            if(newEntry != nullptr){
                writeSemanticError("Multiple variable declaration not allowed", yylineno);
                return 0;
            }
            int idType = $2;
            int valType = $5.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Declaration type mismatch", yylineno);
                return 0;
            }
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
            SymbolTableEntry * entry = addEntryToCurrentTable($3, CONST, idTypeValue, true);

            const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",$3,"",name);
            const char* VarName = assemblyGenerator.getTempVariable($5.nameRep);
            assemblyGenerator.addQuadruple("ASSIGN",VarName,"",name);
        }
        | CONSTANT dataType IDENTIFIER ';'
        {
            writeSemanticError("Constant variable not initialized ", yylineno);
            return 0;
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
        ')' scopeBlock { assemblyGenerator.endScope(ifScope);}
        elseIfCondition 
        elseStmnt 
        ;

elseIfCondition: elseIfCondition ELSE IF '(' expression
        {
            if ($5.type != BOOL_TYPE)
            {
                writeSemanticError("Condition of ELSE IF must be boolean", yylineno);
                return 0;
            }
        }
        ')' scopeBlock { 
            assemblyGenerator.endScope(elseIfScope); }
        |
        ;

elseStmnt: ELSE scopeBlock { 
        assemblyGenerator.endScope(elseScope);}
        |
        ;

/* Switch Case */
switchBlock: '{' {createNewSymbolTable();
    assemblyGenerator.startScope();

} caseExpression {scopeEnd();} '}'                     
    ;

caseExpression:	
            caseDefault 	                   
    |       CASE switchValidValue ':' codeBlock {assemblyGenerator.endScope(caseScope);} BREAK ';' caseExpression  
	;

switchValidValue: INTEGER_VALUE 
{ 
        string valueStr = to_string($1.ival);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        // $$.nameRep = strdup(valueStr.c_str());
        }
| CHARACTER 
{ 
        string valueStr = to_string($1.cval);
        const char* name = assemblyGenerator.addTempVariable(valueStr , "" , "");
        assemblyGenerator.addQuadruple("ASSIGN", valueStr, "", name);
        $$.nameRep = strdup(valueStr.c_str());
        }
        ;

caseDefault:
            DEFAULT ':' codeBlock {
                assemblyGenerator.endScope(defaultScope);} BREAK ';'    		            	 
            | DEFAULT ':' codeBlock {
                assemblyGenerator.endScope(defaultScope);}    		                    	 
            |                                                       	 
    ;

/* Loops and Scope */
forLoopInitialization: assignment ';'
        | variableDeclarationWithAssignment 
        | ';'                        
        ;

forLoopItter: ';' assignment
        | ';' expression
        | ';'
        ;

scopeBlock: '{' 
{
    printf("**************** Scope Block ****************\n");
    createNewSymbolTable();
    assemblyGenerator.startScope();
} codeBlock {
    scopeEnd();
} '}'                                             
    ;

loopsScopeBlock: '{' {
            assemblyGenerator.startScope();
}codeBlock {scopeEnd();} '}'                                                                  
    ;

/////////////////////////////// Function ///////////////////////////////

function :  dataType IDENTIFIER '(' 
        {
            string functionName = string($2) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>($1);
            EntryType funcOut = static_cast<EntryType>($1);
            addEntryToCurrentTable($2, FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();

            
        } ArgList ')' '{' codeBlock '}'  
        {
            printf("**************** Function1 ****************\n");
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }
            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
            assemblyGenerator.endScope(funcScope);
            assemblyGenerator.addQuadruple("RET", "", "", "");

        }
        |  dataType IDENTIFIER '(' 
        {
            string functionName = string($2) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            printf("**************** Function2 ****************\n");
            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = static_cast<EntryType>($1);
            EntryType funcOut = static_cast<EntryType>($1);
            addEntryToCurrentTable($2, FUNC, idTypeValue, true, funcOut);
            createNewSymbolTable();
            assemblyGenerator.startScope();


        } ')' '{' codeBlock '}'         
        {
            if(functionHasReturn == false){
                writeSemanticWarning("Function must return a value", yylineno);
            }

            scopeEnd(); 
            currentFunction = nullptr; 
            functionHasReturn = false;
            assemblyGenerator.endScope(funcScope);
            assemblyGenerator.addQuadruple("RET", "", "", "");


        }
        |  VOID_TYPE IDENTIFIER '(' 
        {
            string functionName = string($2) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable($2, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        } ArgList ')' '{' codeBlock '}' {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");


        }
        |  VOID_TYPE IDENTIFIER '(' 
        {
            string functionName = string($2) + ":";
            assemblyGenerator.addQuadruple(functionName, "", "", "");

            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Multiple function declaration not allowed", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            idTypeValue->type = VOID_DTYPE;
            addEntryToCurrentTable($2, FUNC, idTypeValue, true, VOID_DTYPE);
            createNewSymbolTable();
            assemblyGenerator.startScope();

        } ')' '{' codeBlock '}'         {scopeEnd(); currentFunction = nullptr;
                    assemblyGenerator.endScope(funcScope);
                    assemblyGenerator.addQuadruple("ENDFUNC", "", "", "");

}
        ;

ArgList:  Arg ',' ArgList | Arg ;

Arg: dataType IDENTIFIER 		      
        {
            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            EntryType paramType = static_cast<EntryType>($1);
            idTypeValue->type = paramType;
            currentFunction->pushFunctionInput(paramType);
            SymbolTableEntry * entry = addEntryToCurrentTable($2, PAR, idTypeValue, true);

             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",$2,"",name);
            
        }
        | dataType IDENTIFIER ASSIGN constantValue 
        {
            SymbolTableEntry *newEntry = identifierScopeCheck($2);
            if(newEntry != nullptr){
                writeSemanticError("Already declared variable", yylineno);
                return 0;
            }
            int idType = $1;
            int valType = $4.type;
            if (typeMismatch(idType, valType))
            {
                writeSemanticError("Function parameter intialization type mismatch", yylineno);
                return 0;
            }
            TypeValue* idTypeValue = new TypeValue;
            EntryType paramType = static_cast<EntryType>(idType);
            idTypeValue->type = paramType;
            currentFunction->pushFunctionInput(paramType);
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
            SymbolTableEntry * entry = addEntryToCurrentTable($2, PAR, idTypeValue, true);
             const char* name = assemblyGenerator.assignRegister(entry);
            assemblyGenerator.addQuadruple("ALLOC",$2,"",name);
            
        }  
        ;



ReturnCase: RETURN ';'
        {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != VOID_DTYPE){
                writeSemanticError("Function must return a value", yylineno);
                return 0;
            }
        }
        | RETURN  dataValue ';'
        {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != $2.type){
                writeSemanticError("Return type mismatch", yylineno);
                return 0;
            }
            functionHasReturn = true;
        }
        |
        {
            if (currentFunction == nullptr)
            {
                writeSemanticError("Return should be inside function block", yylineno);
                return 0;
            }
            if(currentFunction->getFunctionOutput() != VOID_DTYPE){
                writeSemanticError("Function must return a value", yylineno);
                return 0;
            }
        }
        ;

TypedFunctionCall: IDENTIFIER '(' 
        {
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry($1);
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            insertFuncParamsToStack(entry);
        } CallList ')'   
        {
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
            SymbolTableEntry *entry = getIdentifierEntry($1);
            switch((int)entry->getFunctionOutput()){
                case INT_TYPE:
                    $$.type = INT_TYPE;
                    $$.ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    $$.fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    $$.type = STRING_TYPE;
                    $$.sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    $$.type = BOOL_TYPE;
                    $$.bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    $$.type = CHAR_TYPE;
                    $$.cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    $$.type = VOID_DTYPE;
                    break;
            }
        }		                                 
        | IDENTIFIER '(' ')'
        {
            SymbolTableEntry *entry = getIdentifierEntry($1);
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            switch((int)entry->getFunctionOutput()){
                case INT_TYPE:
                    $$.type = INT_TYPE;
                    $$.ival = entry->getTypeValue()->value.ival;
                    break;
                case FLOAT_TYPE:
                    $$.type = FLOAT_TYPE;
                    $$.fval = entry->getTypeValue()->value.fval;
                    break;
                case STRING_TYPE:
                    $$.type = STRING_TYPE;
                    $$.sval = entry->getTypeValue()->value.sval;
                    break;
                case BOOL_TYPE:
                    $$.type = BOOL_TYPE;
                    $$.bval = entry->getTypeValue()->value.bval;
                    break;
                case CHAR_TYPE:
                    $$.type = CHAR_TYPE;
                    $$.cval = entry->getTypeValue()->value.cval;
                    break;
                case VOID_DTYPE:
                    $$.type = VOID_DTYPE;
                    break;
            }
        }  		                                                         
        ;

VoidFunctionCall: IDENTIFIER '(' 
        { 
            // Enter func args
            SymbolTableEntry *entry = getIdentifierEntry($1);
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
            insertFuncParamsToStack(entry);
        }
        CallList ')'   		 
        {
            // End of func call
            if(functionParameters.size() != 0)
            {
                writeSemanticError("Invalid arguments size", yylineno);
                return 0;
            }
        }                                     
        | IDENTIFIER '(' ')' 
        {
            SymbolTableEntry *entry = getIdentifierEntry($1);
            if(entry == nullptr){
                writeSemanticError("Undeclared function", yylineno);
                return 0;
            }
            if(entry->getKind() != FUNC)
            {
                writeSemanticError("Call must be of a function", yylineno);
                return 0;
            }
            entry->setused(true);
        }   		                                                        
        ;

CallList:  CallList ',' dataValue 
        {
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)$3.type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        }
        |  dataValue  
        {
            if(functionParameters.size() == 0)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            if((int)functionParameters.top() != (int)$1.type)
            {
                writeSemanticError("Invalid arguments", yylineno);
                return 0;
            }
            functionParameters.pop();
        }
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
	printGreen("PARSE SUCCESSFUL\n");

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