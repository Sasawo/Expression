#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>

class Operators {
public:
	static bool is_operator(char op);
	static int get_precedence(char op);
};

#endif
