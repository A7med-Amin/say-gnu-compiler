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

SymbolTable *currentSymbolTable;
SymbolTable *rootSymbolTable;         // Root symbol table (Akbar parent fehom)
SymbolTableEntry *currentFunction = NULL;
stack<EntryType> functionParameters;

// Define a variant that can hold any of the specified types
using valueVariant = std::variant<int, float, bool, char*, char>;

FILE *semanticFile = fopen("semantic_error.txt", "w");
FILE *quadrupleFile = fopen("quadruple.txt", "w");
FILE *syntaxFile = fopen("syntax_error.txt", "w");
ofstream symbolTablesFile("symbol_table.txt");

void Init();
void createNewSymbolTable();
void addEntryToCurrentTable(char *identifier, Kind kind, TypeValue *typeValue, bool isInitialized,  EntryType functionOutput = VOID);
SymbolTableEntry *getIdentifierEntry(const char *identifier);
void scopeEnd();
EntryType checkIdientifierType(char *identifier);
bool typeMatch(int type1, int type2);
void insertFuncParamsToStack(SymbolTableEntry *currentFunc);

void symbolTableWrite(SymbolTable *table, int level, ofstream &outputFile);
void printSymbolTables();

void printSemanticError(string error, int codeLine);
void printSemanticWarning(string warning, int codeLine);
void printSyntaxError(string error, int codeLine);
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