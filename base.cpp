#include "base.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"


Base* Base::parse(char** input, int length) {
    Base* firstVal = new Op(input[1][0] - 48);
    for (int i = 2; i < length; i++) {
        if (input[i] == "*") {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Mult(firstVal, anotherVal);
            i++;
        }
        else if (input[i] == "**") {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Pow(firstVal, anotherVal);
            i++;
        }
        else if (input[i] == "/") {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Div(firstVal, anotherVal);
            i++;
        }
        else if (input[i] == "+") {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Add(firstVal, anotherVal);
            i++;
        }
        else if (input[i] == "-") {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Sub(firstVal, anotherVal);
            i++;
        }
        else {
            Base* firstVal = nullptr;
        }
    }
    return firstVal;
}