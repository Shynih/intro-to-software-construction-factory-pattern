#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "factory.hpp"

class Base {
    private:
        Factory* fact;
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        Base* parse(char** input, int length) {
            return fact -> parse(input, length);
        }


};

#endif //__BASE_HPP__
