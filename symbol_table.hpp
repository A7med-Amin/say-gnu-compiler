#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<unordered_map>
#include <iostream>
#include <vector>
using namespace std;

enum Kind{
    VAR,
    CONST,
    FUNC,
    PAR
};

enum EntryType{
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    BOOL_TYPE,
    CHAR_TYPE,
    VOID_DTYPE
};

struct TypeValue{
        EntryType type;
        char* nameRep;
        union {
        int ival;
        float fval;
        char cval;
        char* sval; // For string values
        bool bval; 
        } value;
};

class SymbolTableEntry{
    private:
        string name;
        Kind kind;
        TypeValue* typeValue;
        bool initialization = false;
        bool used = false;
        bool modifiable = true;        // when variable is constant so it is false
        EntryType functionOutput;
        vector<EntryType> functionInput;
    
    public:
        // Setters
        void setName(const string& newName) { name = newName; }
        void setKind(Kind newKind) { kind = newKind; }
        void setTypeValue(TypeValue* newTypeValue) { typeValue = newTypeValue; }
        void setinitialization(bool newinitialization) { initialization = newinitialization; }
        void setused(bool newused) { used = newused; }
        void setModifiable(bool newModifiable) { modifiable = newModifiable; }
        void setFunctionOutput(EntryType newFunctionOutput) { functionOutput = newFunctionOutput; }
        void setFunctionInput(const vector<EntryType>& newFunctionInput) { functionInput = newFunctionInput; }

        // Getters
        string getName() const { return name; }
        Kind getKind() const { return kind; }
        TypeValue* getTypeValue() const { return typeValue; }
        bool getinitialization() const { return initialization; }
        bool getused() const { return used; }
        bool getModifiable() const { return modifiable; }
        EntryType getFunctionOutput() const { return functionOutput; }
        const vector<EntryType>& getFunctionInput() const { return functionInput; }
};

class SymbolTable
{
    private:
        unordered_map<string, SymbolTableEntry*> entries;
        SymbolTable* parent = NULL;
        vector<SymbolTable *> children;  // 3eyal table dh

    public:
        // Setters
        void setParent(SymbolTable* newParent) { parent = newParent; }
        void setEntries(const unordered_map<string, SymbolTableEntry*>& newEntries) { entries = newEntries; }
        void addEntry(const string& key, SymbolTableEntry* entry) { entries[key] = entry; }
        void setChildren(const vector<SymbolTable*>& newChildren) { children = newChildren; }
        void addChild(SymbolTable* child) {
            if (child) {
                children.push_back(child);
                child->setParent(this);  // Automatically set this table as the parent of the child
            }
        }

        // Getters
        SymbolTable* getParent() const { return parent; }
        SymbolTableEntry* getEntry(const string& key) const { // Find the entry with the given key
            auto it = entries.find(key);
            if (it != entries.end()) {
                return it->second;
            }
            return nullptr; // Return nullptr if key is not found
        }
        const vector<SymbolTable*>& getChildren() const { return children; }
        const unordered_map<string, SymbolTableEntry*>& getEntries() const { return entries; }
};

#endif 