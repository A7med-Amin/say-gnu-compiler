#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

#include "quadruple.hpp"
#include "./semantic_analyzer.hpp"

class AssemblyGenerator
{
private:
    std::vector<Quadruple*>* quadruples;
    std::stack<std::vector<Quadruple*>*> scopes;
    std::unordered_map<SymbolTableEntry*, std::string> assignments;
    std::unordered_map<std::string, std::string> temps;

public:
    // static int labelCount;
    AssemblyGenerator();
    // void startScope();
    // void endScope(std::string type);
    const char *addAssignment(SymbolTableEntry* sym);
    const char *getAssignment(SymbolTableEntry* sym);
    const char *addTemp(const string& expr1, const string& op, const string& expr2);
    const char *getTemp(const string& temp);
    void clearTemps();
    void addQuad(const string& operation, const string& operand1, const string& operand2, const string& destination);
    // void printQuads();
    // void printQuadsToFile();
};

