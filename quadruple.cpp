#include "quadruple.hpp"
using namespace std;

// Constructor for Quadruple
Quadruple::Quadruple(string o, string a1, string a2, string res)
    : op(o), arg1(a1), arg2(a2), result(res) {
        this->op = o;
        this->arg1 = a1;
        this->arg2 = a2;
        this->result = res;
    }

// setters
void Quadruple::setOp(string o) { this->op = o; }
void Quadruple::setArg1(string a1) { this->arg1 = a1; }
void Quadruple::setArg2(string a2) { this->arg2 = a2; }
void Quadruple::setResult(string res) { this->result = res; }

// getters
string Quadruple::getOp() { return this->op; }
string Quadruple::getArg1() { return this->arg1; }
string Quadruple::getArg2() { return this->arg2; }
string Quadruple::getResult() { return this->result; }

