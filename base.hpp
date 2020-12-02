#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        Base* parse(char** input, int length);
};

#endif //__BASE_HPP__
