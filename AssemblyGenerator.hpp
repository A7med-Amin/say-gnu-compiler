#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

#include "quadruple.hpp"
#include "./semantic_analyzer.hpp"

enum scopeType
{
    ifScope,
    whileScope,
    elseScope,
    elseIfScope,
    forScope,
    funcScope,
    switchScope,
    caseScope,
    defaultScope,
    enumScope,
    repeatScope

};

class AssemblyGenerator
{
private:
    std::vector<Quadruple*>* quadruples;
    std::stack<std::vector<Quadruple*>*> scopes;
    std::unordered_map<SymbolTableEntry*, std::string> assignments;
    std::unordered_map<std::string, std::string> temps;
    std::vector<string> labels;
    string usedSwitchVar = "";

public:
    // static int labelCount;
    AssemblyGenerator();
    void startScope();
    void endScope(scopeType type);
    const char *assignRegister(SymbolTableEntry* sym);
    const char *getRegisterAssignment(SymbolTableEntry* sym);
    const char *addTempVariable( string expr1,  string op,  string expr2);
    const char *getTempVariable(string temp);
    void clearTemps();
    void addQuadruple(const string& operation, const string& operand1, const string& operand2, const string& destination);
    // void printQuads();
    void printQuadsToFile();
};

