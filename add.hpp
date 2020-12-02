#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>

class Add : public Base {
    private:
        double result;
        std::string sentence;
    public:
        Add(Base* val1, Base* val2) : Base() {
            result = val1 ->evaluate() + val2->evaluate();
            std::stringstream stream;
            stream << val1 -> stringify()  << " + " << val2 -> stringify();
            sentence = stream.str();
        }
        virtual double evaluate() {
            return result; 
        }
        virtual std::string stringify() { 
            return sentence;
        }
};

#endif 
