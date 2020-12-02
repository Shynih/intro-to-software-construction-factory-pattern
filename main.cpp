#include <iostream> 
#include "op.hpp"
#include "base.hpp"

using namespace std; 

int main(int argc, char** argv) { 
   Base* parse;
	parse -> parse(argv, argc);

   return 0; 
} 
