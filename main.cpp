#include "Expression.h"

int main() {
	try {
		Expression e1("10*2+3*((1+14)-18)-10");
		e1.print_infix();
	}
	catch (Exception e) { std::cout << e.message(); }
}