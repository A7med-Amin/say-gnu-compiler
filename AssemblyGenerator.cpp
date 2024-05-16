#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "./semantic_analyzer.hpp"

#include "assemblyGenerator.hpp"

using namespace std;

AssemblyGenerator::AssemblyGenerator()
{
    quadruples = new vector<Quadruple *>();
    scopes.push(quadruples);
}

void AssemblyGenerator::startScope()
{
    cout << "Starting scope" << endl;
    vector<Quadruple *> *newQuadruples = new vector<Quadruple *>();
    scopes.push(newQuadruples);
}

void AssemblyGenerator::endScope(scopeType type)
{
    vector<Quadruple *> *currentScopeQuadruples = scopes.top();
    scopes.pop();

    vector<Quadruple *> *previousScopeQuadruples = scopes.top();

    switch (type)
    {
    case ifScope:
    {
        string label = "L" + to_string(labels.size());
        string lastResult = previousScopeQuadruples->back()->getResult();
        addQuadruple("JF", lastResult, "", label);
        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);

    }
    break;

    case elseScope:
    {
        string label = "L" + to_string(labels.size());
        auto lastQuad = previousScopeQuadruples->end() ;

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }

    }
    break;

    case elseIfScope:
    {
        string label = "L" + to_string(labels.size());
        string lastResult = previousScopeQuadruples->back()->getResult();
        addQuadruple("JF", lastResult, "", label);

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }

        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);
    }
    break;

    case forScope:
    {
        cout << "FOR SCOPE" << endl;
        string label = "L" + to_string(labels.size());
        auto lastQuad = previousScopeQuadruples->end() - 1;
        previousScopeQuadruples->insert(lastQuad, new Quadruple(label + ":", "", "", ""));
        labels.push_back(label);  

        string lastResult2 = previousScopeQuadruples->at(previousScopeQuadruples->size() - 3)->getResult();
        label = "L" + to_string(labels.size());
        lastQuad = previousScopeQuadruples->end() - 1;
        previousScopeQuadruples->insert(lastQuad, new Quadruple("JF", lastResult2, "", label));

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }

        string previousLabel = labels.back();
        addQuadruple("JMP", "", "", previousLabel);
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);         

    }
    break;

    case whileScope:
    {
        cout << "WHILE SCOPE" << endl;
        string label = "L" + to_string(labels.size());
        auto lastQuad = previousScopeQuadruples->end() - 1;
        previousScopeQuadruples->insert(lastQuad, new Quadruple(label + ":", "", "", ""));
        labels.push_back(label);  

        string lastResult2 = previousScopeQuadruples->at(previousScopeQuadruples->size() - 1)->getResult();
        label = "L" + to_string(labels.size());
        addQuadruple("JF", lastResult2, "", label);

        // lastQuad = previousScopeQuadruples->end() - 1;
        // previousScopeQuadruples->insert(lastQuad, new Quadruple("JF", lastResult2, "", label));

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }

        string previousLabel = labels.back();
        addQuadruple("JMP", "", "", previousLabel);
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);         
    }
    break;

    case repeatScope:
    {
        cout << "REPEAT SCOPE" << endl;
        string label = "L" + to_string(labels.size());
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }
        string lastResult2 = previousScopeQuadruples->at(previousScopeQuadruples->size() - 1)->getResult();
        label = "L" + to_string(labels.size());
        addQuadruple("JF", lastResult2, "", label);

        string previousLabel = labels.back();
        addQuadruple("JMP", "", "", previousLabel);
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);  
    }
    break;

    case switchScope:
    {
        cout << "SWITCH SCOPE" << endl;
        
        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }

        string label = "L" + to_string(labels.size());
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);

    }
    break;

    case caseScope:
    {
        cout<<"CASE SCOPE" << endl;

          string label = "L" + to_string(labels.size());
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);  



            for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }
    }
    break;

    case defaultScope:
    {
        cout<<"DEFAULT SCOPE" << endl;

          string label = "L" + to_string(labels.size());
        addQuadruple(label + ":", "", "", "");
        labels.push_back(label);  

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }
    }
    break;

    case funcScope:
    {
        cout << "FUNC SCOPE" << endl;

        for (auto *quad : *currentScopeQuadruples)
        {
            previousScopeQuadruples->push_back(quad);
        }
    }

    default:
        break;
    }
}

const char *AssemblyGenerator::assignRegister(SymbolTableEntry *sym)
{
    if (!sym)
    {
        cout << "SymbolTableEntry is null" << endl;
        return nullptr;
    }
    try
    {
        // cout << "Looking for: " << sym->getName() << endl;
        // cout << "Found: " << sym->getName() << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception occurred: " << e.what() << endl;
        return nullptr;
    }

    assignments[sym] = "R" + to_string(assignments.size());

    string str_value = assignments[sym];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';

    // cout << "Assignments size: " << assignments.size() << endl;
    // cout << "Assignments: " << endl;
    // for (const auto &assignment : assignments)
    // {
    //     cout << assignment.first << " = " << assignment.second << endl;
    // }

    return cstr_value;
}

const char *AssemblyGenerator::getRegisterAssignment(SymbolTableEntry *sym)
{
    auto it = assignments.find(sym);
    if (it != assignments.end())
    {
        return strdup(it->second.c_str());
    }
    return nullptr;
}

const char *AssemblyGenerator::addTempVariable(string expr1, string op, string expr2)
{
    string tempName = "T" + to_string(temps.size());
    temps[tempName] = expr1 + op + expr2;

    // cout << "Temps size: " << temps.size() << endl;
    // cout << "Temps: " << endl;
    // for (auto it = temps.begin(); it != temps.end(); it++) {
    //     cout << it->first << " = " << it->second << endl;
    // }

    return strdup(tempName.c_str());
}

const char *AssemblyGenerator::getTempVariable(string temp)
{
    for (auto it = temps.begin(); it != temps.end(); it++)
    {
        if (it->second == temp)
        {
            return strdup(it->first.c_str());
        }
    }

    printf("Could not find temp variable: %s\n", temp.c_str());
    return nullptr;
}

void AssemblyGenerator::clearTemps()
{
    temps.clear();
}

void AssemblyGenerator::addQuadruple(const string &operation, const string &operand1, const string &operand2, const string &destination)
{
    scopes.top()->push_back(new Quadruple(operation, operand1, operand2, destination));
}

void AssemblyGenerator::printQuadsToFile()
{
    // Open the file for writing
    ofstream outputFile("quadruples.txt");

    if (!outputFile)
    {
        cerr << "Error opening file." << endl;
        return;
    }

    outputFile << "START main" << endl
               << endl;

    for (int i = 0; i < quadruples->size(); i++)
    {
        outputFile << left << setw(10) << (*quadruples)[i]->getOp() << setw(6) << (*quadruples)[i]->getArg1() << setw(6) << (*quadruples)[i]->getArg2() << setw(6) << (*quadruples)[i]->getResult() << endl;
    }

    // Close the file
    outputFile.close();
}
