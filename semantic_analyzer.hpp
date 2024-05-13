#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include <variant>
#include "symbol_table.hpp"

// Define a variant that can hold any of the specified types
using valueVariant = std::variant<int, float, bool, char*, char>;

void initSymbolTable();
void createNewSymbolTable();
void addEntryToCurrentTable(char *identifier, Kind kind, TypeValue *typeValue, bool isInitialized,  EntryType functionOutput = VOID);
SymbolTableEntry *getIdentifierEntry(const char *identifier);
void scopeEnd();
EntryType checkIdientifierType(char *identifier);
bool typeMatch(int type1, int type2);
void insertFuncParamsToStack(SymbolTableEntry *currentFunc);

// Save Symbol Tables
void symbolTableWrite(SymbolTable *table, int level, ofstream &outputFile);
void saveSymbolTables();
// Error Handling
void writeSemanticError(string error, int codeLine);
void writeSemanticWarning(string warning, int codeLine);
void writeSyntaxError(string error, int codeLine);

SymbolTableEntry *identifierScopeCheck(char *identifier);
void checkIsBool(bool isBool, int codeLine);
TypeValue *convertTypeValToEntry(int type, const valueVariant &value);
bool checkEqualityEqual(TypeValue *val1, TypeValue *val2);
bool checkEqualityNot(TypeValue *val1, TypeValue *val2);
bool checkEqualityGTE(TypeValue *val1, TypeValue *val2);
bool checkEqualityLTE(TypeValue *val1, TypeValue *val2);
bool checkEqualityGT(TypeValue *val1, TypeValue *val2);
bool checkEqualityLT(TypeValue *val1, TypeValue *val2);

#endif