#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <iomanip>
#include <sstream>

class Pow : public Base {
    private:
        double result;
        std::string sentence;
    public:
        Pow(Base* val1, Base* val2) : Base() {
			if (val1->evaluate() == 0) {
				result = 1.0;
				sentence = "1.0";
				return;
			}	
            result = val1 -> evaluate();
            for (int i = 0; i < val2 -> evaluate()-1; i++) {
                result = result * val1 -> evaluate();
            }
            std::stringstream stream;
            stream << val1 -> stringify() << " ** " << val2 -> stringify();
            sentence = stream.str();
        }
        virtual double evaluate() {
            return result; 
        }
        virtual std::string stringify() { 
            return sentence;
        }
};

#endif //__POW_HPP__
