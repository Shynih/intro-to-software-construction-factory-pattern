#include <iostream> 
#include "base.cpp"

using namespace std; 

int main(int argc, char** argv) { 
   Base* parse;
   parse = parse -> parse(argv, argc);
   cout << parse -> stringify();

   return 0; 
} 
