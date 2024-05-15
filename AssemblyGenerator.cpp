#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "./semantic_analyzer.hpp"

#include "assemblyGenerator.hpp"

using namespace std;


AssemblyGenerator::AssemblyGenerator()
{
    quadruples = new vector<Quadruple*>();
}

const char* AssemblyGenerator::addAssignment(SymbolTableEntry* sym) {
    string reg = "R" + to_string(assignments.size());
    assignments[sym] = reg;
    return strdup(reg.c_str());
}

const char* AssemblyGenerator::getAssignment(SymbolTableEntry* sym) {
    auto it = assignments.find(sym);
    if (it != assignments.end()) {
        return strdup(it->second.c_str());
    }
    return nullptr;
}

const char* AssemblyGenerator::addTemp(const string& expr1, const string& op, const string& expr2) {
    string tempName = "T" + to_string(temps.size());
    temps[tempName] = expr1 + op + expr2;
    return strdup(tempName.c_str());
}

const char* AssemblyGenerator::getTemp(const string& temp) {
    auto it = temps.find(temp);
    if (it != temps.end()) {
        return strdup(it->second.c_str());
    }
    return nullptr;
}

void AssemblyGenerator::clearTemps() {
    temps.clear();
}

void AssemblyGenerator::addQuad(const string& operation, const string& operand1, const string& operand2, const string& destination) {
    scopes.top()->push_back(new Quadruple(operation, operand1, operand2, destination));
}
