#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "sstream"
#include <string>
#include <iomanip>

class Op : public Base {
    private:
        double value;
    public:
        Op(double value) : Base() { this -> value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
			std::stringstream stream;
			std::string sentence;
			stream << std::fixed << std::setprecision(1) << value;
			sentence = stream.str();
			return sentence;
		}
};

#endif //__OP_HPP__
