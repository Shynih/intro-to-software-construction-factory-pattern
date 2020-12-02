#include <iostream> 
#include "base.cpp"

using namespace std; 

int main(int argc, char** argv) { 
   Base* parse;
   parse = parse -> parse(argv, argc);
   if (parse != nullptr) {
   		cout << parse -> stringify() << " = " << parse -> evaluate() << endl;
   }

   return 0; 
} 
