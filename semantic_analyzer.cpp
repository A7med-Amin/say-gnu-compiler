#include "semantic_analyzer.hpp"


void initSymbolTable()
{
    currentSymbolTable = new SymbolTable();         // root symbol table
    unordered_map<string, SymbolTableEntry *> map;
    vector<SymbolTable *> children;
    currentSymbolTable->setChildren(children);
    currentSymbolTable->setEntries(map);
    rootSymbolTable = currentSymbolTable;
}

void createNewSymbolTable()
{
    SymbolTable *newSymbolTable = new SymbolTable();
    unordered_map<string, SymbolTableEntry *> map;
    vector<SymbolTable *> children;
    newSymbolTable->setChildren(children);;
    newSymbolTable->setEntries(map);
    currentSymbolTable->addChild(newSymbolTable);
    currentSymbolTable = newSymbolTable;
}

void addEntryToCurrentTable(char *identifier, Kind kind, TypeValue *typeValue, bool isInitialized,  EntryType functionOutput = VOID)
{
    string id(identifier);              // convert char* to string
    SymbolTableEntry *entry = new SymbolTableEntry();
    entry->setName(id);
    entry->setKind(kind);
    entry->setTypeValue(typeValue);
    entry->setinitialization(isInitialized);
    entry->setFunctionOutput(functionOutput);
    entry->setFunctionInput(vector<EntryType>());
    if (kind == FUNC)
        currentFunction = entry;
    if (kind == CONST)
        entry->setModifiable(false); // Constants are not modifiable
    currentSymbolTable->addEntry(id, entry);
}

SymbolTableEntry *getIdentifierEntry(const char *identifier)
{
    const string id(identifier);
    SymbolTable *temp = currentSymbolTable;

    while (currentSymbolTable != nullptr) {
        const auto& map = currentSymbolTable->getEntries();
        auto entry = map.find(id);
        if (entry != map.end()) {
            currentSymbolTable = temp; // Restore currentSymbolTable before returning
            return entry->second; // Return the found entry
        }
        currentSymbolTable = currentSymbolTable->getParent(); // Move to the parent
    }

    currentSymbolTable = temp; // Restore currentSymbolTable if nothing is found
    return nullptr; // Return nullptr if no entry is found
}

void scopeEnd()
{
    currentSymbolTable = currentSymbolTable->getParent();
}

EntryType checkIdientifierType(char *identifier)
{
    SymbolTableEntry *entry = getIdentifierEntry(identifier);
    if (entry == NULL)
        return VOID;
    return entry->getTypeValue()->type;
}

bool typeMatch(int type1, int type2)
{
    if (type1 == type2)
        return true;
    return false;
}

void insertFuncParamsToStack(SymbolTableEntry *currentFunc)
{
    functionParameters = stack<EntryType>();
    for (int i = currentFunc->getFunctionInput().size() - 1; i >= 0; i--)
    {
        functionParameters.push(currentFunc->getFunctionInput()[i]);
    }
}

SymbolTableEntry *identifierScopeCheck(char *identifier)
{
    string id(identifier);
    unordered_map<string, SymbolTableEntry *> map = currentSymbolTable->getEntries();
    auto entry = map.find(id);
    if (entry == map.end())
    {
        return nullptr;
    }
    else
    {
        return entry->second;
    }
}

void checkIsBool(bool isBool, int codeLine)
{  // Check if the type is bool for if condition and while condition
    if (isBool)
        writeSemanticError("Condition must be boolean at line", codeLine);
}

TypeValue *convertTypeValToEntry(int type, const valueVariant &value)
{
    TypeValue *typeVal = new TypeValue();
    typeVal->type = static_cast<EntryType>(type);
    
    std::visit([&](auto&& arg) {
        switch (typeVal->type) {
        case INTEGER:
            typeVal->value.ival = get<int>(value);
            break;
        case FLOAT:
            typeVal->value.fval = get<float>(value);
            break;
        case CHARACTAR:
            typeVal->value.cval = get<char>(value);
            break;
        case STRING:
            typeVal->value.sval = get<char*>(value);
            break;
        case BOOL:
            typeVal->value.bval = get<bool>(value);
            break;
        default:
            break;
        }
    }, value);
    
    return typeVal;
}

bool checkEqualityEqual(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival == val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval == val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval == val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval == val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) == 0;
    else
        return false;
}

bool checkEqualityNot(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival != val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval != val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval != val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval != val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) != 0;
    else
        return false;
}

bool checkEqualityGTE(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival >= val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval >= val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval >= val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval >= val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) >= 0;
    else
        return false;
}

bool checkEqualityLTE(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival <= val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval <= val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval <= val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval <= val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) <= 0;
    else
        return false;
}

bool checkEqualityGT(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival > val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval > val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval > val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval > val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) > 0;
    else
        return false;
}

bool checkEqualityLT(TypeValue *val1, TypeValue *val2)
{
    if (val1->type == INTEGER)
        return val1->value.ival < val2->value.ival;
    else if (val1->type == FLOAT)
        return val1->value.fval < val2->value.fval;
    else if (val1->type == BOOL)
        return val1->value.bval < val2->value.bval;
    else if (val1->type == CHARACTAR)
        return val1->value.cval < val2->value.cval;
    else if (val1->type == STRING)
        return strcmp(val1->value.sval, val2->value.sval) < 0;
    else
        return false;
}


// ***************************************************** ERROR HANDLERS *****************************************************

void writeSemanticError(string error, int codeLine)
{
    fprintf(semanticFile, "%s at line %d\n", error.c_str(), codeLine);
    printf("Semantic errors\n");
    saveSymbolTables();
    exit(0);
}

void writeSemanticWarning(string warning, int codeLine)
{
    fprintf(semanticFile, "%s at line %d\n", warning.c_str(), codeLine);
}

void writeSyntaxError(string error, int codeLine)
{
    fprintf(syntaxFile, "%s at line %d\n", error.c_str(), codeLine);
    printf("Syntax errors\n");
    saveSymbolTables();
    exit(0);
}


// TODO: Check This Functions
void symbolTableWrite(SymbolTable *table, int level, ofstream &outputFile)
{
    outputFile << setw(level * 4) << ""
            << "Identifier"
            << setw(12) << "Level"
            << setw(12) << "Kind"
            << setw(12) << "Type"
            << setw(18) << "Value" << endl;
    outputFile << setw(level * 4) << ""
            << "----------"
            << setw(12) << "-----"
            << setw(12) << "----"
            << setw(12) << "----"
            << setw(18) << "----" << endl;

    for (const auto &entry : table->getEntries())
    {
        SymbolTableEntry *symbolEntry = entry.second;
        TypeValue *typeValue = symbolEntry->getTypeValue();

        outputFile << setw(level * 4) << "" << entry.first
                << setw(18) << level;
        switch (symbolEntry->getKind())
        {
        case CONST:
            outputFile << setw(14) << "CONST";
            break;
        case VAR:
            outputFile << setw(14) << "VAR";
            break;
        case FUNC:
            outputFile << setw(14) << "FUNC";
            break;
        case PAR:
            outputFile << setw(14) << "PAR";
            break;
        }
        switch (typeValue->type)
        {
        case INTEGER:
            outputFile << setw(16) << "INT_TYPE";
            if (symbolEntry->getKind() == VAR || symbolEntry->getKind() == CONST)
                outputFile << setw(15) << typeValue->value.ival;
            break;
        case FLOAT:
            outputFile << setw(16) << "FLOAT_TYPE";
            if (symbolEntry->getKind() == VAR || symbolEntry->getKind() == CONST)
                outputFile << setw(15) << typeValue->value.fval;
            break;
        case STRING:
            outputFile << setw(16) << "STRING_TYPE";
            if (symbolEntry->getKind() == VAR || symbolEntry->getKind() == CONST)
                outputFile << setw(15) << typeValue->value.sval;
            break;
        case BOOL:
            outputFile << setw(16) << "BOOL_TYPE";
            if (symbolEntry->getKind() == VAR || symbolEntry->getKind() == CONST)
                outputFile << setw(15) << typeValue->value.bval;
            break;
        case CHARACTAR:
            outputFile << setw(16) << "CHAR_TYPE";
            if (symbolEntry->getKind() == VAR || symbolEntry->getKind() == CONST)
                outputFile << setw(15) << typeValue->value.cval;
            break;
        case VOID:
            outputFile << setw(16) << "VOID_TYPE";
            break;
        }
        outputFile << endl;
        if (entry.second->getused() == false)
            fprintf(semanticFile, "Warning: %s is declared but not used\n", entry.first.c_str());
    }

    outputFile << endl;

    for (SymbolTable *child : table->getChildren())
    {
        symbolTableWrite(child, level + 1, outputFile);
    }
}

void saveSymbolTables()
{
    symbolTableWrite(rootSymbolTable, 0, symbolTablesFile);
    symbolTablesFile.close();
    fclose(semanticFile);
    fclose(quadrupleFile);
    fclose(syntaxFile);
}
