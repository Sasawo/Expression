#include "Operators.h"
#include "Constants.h"

bool Operators::is_operator(char op) {
	if (op == ADDITION_SIGN || op == SUBTRACTION_SIGN || op == MULTIPLICATION_SIGN || op == DIVISION_SIGN) { return true; }
	return false;
}

int Operators::get_precedence(char op) {
	if (op == ADDITION_SIGN || op == SUBTRACTION_SIGN) { return LOW_PRECEDENCE; }
	else if (op == MULTIPLICATION_SIGN || op == DIVISION_SIGN) { return HIGH_PRECEDENCE; }
	else { return PRECEDENCE_ERROR; }
}