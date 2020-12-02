#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"

class Op;
class Mult;
class Pow;
class Sub;
class Add;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        Base* parse(char** input, int length) {
            Base* firstVal = new Op(input[1][0] + 48);
            for (int i = 2; i < length; i++) {
                if (input[i] == "*") {
                    Base* anotherVal = new Op(input[i+1][0] + 48);
                    firstVal = new Mult(firstVal, anotherVal);
                    i++;
                }
                else if (input[i] == "**") {
                    Base* anotherVal = new Op(input[i+1][0] + 48);
                    firstVal = new Pow(firstVal, anotherVal);
                    i++;
                }
                else if (input[i] == "/") {
                    Base* anotherVal = new Op(input[i+1][0] + 48);
                    firstVal = new Div(firstVal, anotherVal);
                    i++;
                }
                else if (input[i] == "+") {
                    Base* anotherVal = new Op(input[i+1][0] + 48);
                    firstVal = new Add(firstVal, anotherVal);
                    i++;
                }
                else if (input[i] == "-") {
                    Base* anotherVal = new Op(input[i+1][0] + 48);
                    firstVal = new Sub(firstVal, anotherVal);
                    i++;
                }
                else {
                    Base* firstVal = nullptr;
                }
            }
            return firstVal;
        }
};

#endif //__BASE_HPP__
