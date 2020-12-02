#include "base.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include <iostream>

Base* Base::parse(char** input, int length) {
    Base* firstVal = new Op(input[1][0] - 48);
    for (int i = 2; i < length; i++) {
        if (input[i][0] == '*' && input[i][1] == '*') {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Pow(firstVal, anotherVal);
            i++;
       }
        else if (input[i][0] == '*') {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Mult(firstVal, anotherVal);
            i++;
        }
        else if (input[i][0] == '/') {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Div(firstVal, anotherVal);
            i++;
        }
        else if (input[i][0] == '+') {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Add(firstVal, anotherVal);
            i++;
        }
        else if (input[i][0] == '-') {
            Base* anotherVal = new Op(input[i+1][0] - 48);
            firstVal = new Sub(firstVal, anotherVal);
            i++;
        }
        else if (isdigit(input[i][0])) {}
		else {
			std::cout << "Invalid Input" << std::endl;
            firstVal = nullptr;
			return firstVal;
        }
    }
    return firstVal;
}
