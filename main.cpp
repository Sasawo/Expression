#include "Expression.h"

int main(int argc, char* argv[]) {
	if (argc != 2) { std::cout << "Please enter an equation in infix notation like so: 10*2+3*((1+14)-18)-10"; return 0; }
	try {
		Expression e1(argv[1]);
		std::cout << "Infix notation: ";
		e1.print_infix();
		std::cout << std::endl;
		std::cout << "Postfix notation: ";
		e1.print_postfix();
		std::cout << std::endl;
		std::cout << "Result: " << e1.evaluate();
	}
	catch (Exception e) { std::cout << e.message(); }
}