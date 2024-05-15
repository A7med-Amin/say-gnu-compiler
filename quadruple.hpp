#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include <string>

struct Quadruple {
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;

    Quadruple(std::string op, std::string arg1, std::string arg2, std::string result)
        : op(op), arg1(arg1), arg2(arg2), result(result) {}

    // setters
    void setOp(std::string op);
    void setArg1(std::string arg1);
    void setArg2(std::string arg2);
    void setResult(std::string result);

    // getters
    std::string getOp();
    std::string getArg1();
    std::string getArg2();
    std::string getResult();

};

#endif // QUADRUPLE_HPP