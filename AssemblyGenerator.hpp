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
    const char *assignRegister(SymbolTableEntry* sym);
    const char *getRegisterAssignment(SymbolTableEntry* sym);
    const char *addTempVariable( string expr1,  string op,  string expr2);
    const char *getTempVariable(string temp);
    void clearTemps();
    void addQuad(const string& operation, const string& operand1, const string& operand2, const string& destination);
    // void printQuads();
    void printQuadsToFile();
};

