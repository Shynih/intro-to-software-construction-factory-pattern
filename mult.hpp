#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>

class Op;

class Mult : public Base {
    private:
        double result;
        std::string sentence;
    public:
        Mult(Base* val1, Base* val2) : Base() {
            result = val1 ->evaluate() * val2->evaluate();
            std::stringstream stream;
            stream << val1 -> stringify() << " * " << val2 -> stringify();
            sentence = stream.str();
        }
        virtual double evaluate() {
            return result; 
        }
        virtual std::string stringify() { 
            return sentence;
        }
        virtual Base* parse(char** input, int length) {
            Base* firstVal = new Op(input[1]+48);
            for (int i = 2; i < length; i++) {
                if (input[i] == "*") {
                    Base* anotherVal = new Op(input[i+1] + 48);
                    Base* combined = new Mult(firstVal, anotherVal);
                    i++;
                }
            }
        }
};

#endif 
