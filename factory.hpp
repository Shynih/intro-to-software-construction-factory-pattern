#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

class Base;

class Factory {
    public:
        Factory() {}
        Base* parse(char** input, int length);
};


#endif