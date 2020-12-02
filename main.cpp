#include <iostream> 
#include "op.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

using namespace std; 

int main(int argc, char** argv) { 
   Base* parse;
	parse -> parse(argv, argc);

   return 0; 
} 
