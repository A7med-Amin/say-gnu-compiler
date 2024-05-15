#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <string>
using namespace std;

struct Quadruple {
public:
    string op;
    string arg1;
    string arg2;
    string result;

    // Declare the constructor
    Quadruple(string op, string arg1, string arg2, string result);

    // setters
    void setOp(string op);
    void setArg1(string arg1);
    void setArg2(string arg2);
    void setResult(string result);

    // getters
    string getOp();
    string getArg1();
    string getArg2();
    string getResult();
};

#endif // QUADRUPLE_HPP