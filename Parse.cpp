#include "Parse.h"
#include "Constants.h"
#include "Operators.h"
#include "Exceptions.h"
#include <iostream>

inline int Parser::ctoi(char chr) { return chr - CHAR_ZERO; }

void Parser::deallocate(Node*& opnd) {
		delete opnd;
		opnd = nullptr;
}

void Parser::deallocate(std::stack<Node*>& opnd) {
	while (!opnd.empty()) {
		delete opnd.top();
		opnd.top() = nullptr;
		opnd.pop();
	}
}

void Parser::create_operation(std::stack<char>& optr, std::stack<Node*>& opnd) {
	if (opnd.size() < 2) { throw ParseException(MISSING_OPERAND_PARSE_ERROR); }
	Node* right_opnd = opnd.top(); opnd.pop();
	Node* left_opnd = opnd.top(); opnd.pop();
	char chr = optr.top(); optr.pop();
	Node* new_node = nullptr;
	try {
		switch (chr) {
		case ADDITION_SIGN:
			new_node = new AdditionNode(left_opnd, right_opnd);
			break;
		case SUBTRACTION_SIGN:
			new_node = new SubtractionNode(left_opnd, right_opnd);
			break;
		case MULTIPLICATION_SIGN:
			new_node = new MultiplicationNode(left_opnd, right_opnd);
			break;
		case DIVISION_SIGN:
			new_node = new DivisionNode(left_opnd, right_opnd);
			break;
		}
	} catch(const std::bad_alloc&) { deallocate(left_opnd); deallocate(right_opnd); throw MemoryException(OVERFLOW_MEMORY_ERROR); }
	try_push(opnd, new_node);
}

void Parser::try_push(std::stack<Node*>& opnd, Node* node) {
	try { opnd.push(node); }
	catch (...) { deallocate(node); throw MemoryException(OVERFLOW_MEMORY_ERROR); }
}

int Parser::parse_digit(const std::string& input, const size_t length, unsigned int iterator, std::stack<Node*>& opnd) {
	int end_number = 1;
	int number;
	while (iterator + end_number < length && isdigit(input[iterator + end_number])) { ++end_number; }
	try { number = stoi(input.substr(iterator, end_number)); }
	catch (const std::out_of_range&) { throw ParseException(OVERFLOW_PARSE_ERROR); }
	try_push(opnd, new NumberNode(number));
	return end_number - 1;
}

void Parser::parse_op(const char index, std::stack<Node*>& opnd, std::stack<char>& optr) { 
	while (!optr.empty()) {
		if (Operators::get_precedence(optr.top()) < Operators::get_precedence(index)) { break; }
		create_operation(optr, opnd);
	}
	optr.push(index);
}

void Parser::parse_bracket(std::stack<Node*>& opnd, std::stack<char>& optr) {
	while (!optr.empty() && optr.top() != '(') { create_operation(optr, opnd); }
	if (optr.empty()) { throw ParseException(END_BRACKET_PARSE_ERROR); }
	optr.pop();
}

Node* Parser::parse(const std::string& input) {
	try { return parse_actual(input); }
	catch (const std::bad_alloc&) { throw MemoryException(OVERFLOW_MEMORY_ERROR); }
}

Node* Parser::parse_actual(const std::string& input) {
	size_t length = input.length();
	if (length == 0) { throw ParseException(VOID_PARSE_ERROR); }
	std::stack<Node*> keep_operand;
	std::stack<char> keep_operator;
	try {
		for (unsigned int i = 0; i < length; i++) {
			char index = input[i];
			if (isdigit(index)) { i += Parser::parse_digit(input, length, i, keep_operand); }
			else if (index == '(') { keep_operator.push('('); }
			else if (index == ')') { Parser::parse_bracket(keep_operand, keep_operator); }
			else if (Operators::is_operator(index)) { Parser::parse_op(index, keep_operand, keep_operator); }
			else { throw ParseException(UNKNOWN_PARSE_ERROR); }
		}
		while (keep_operator.size() > 0) {
			if (keep_operator.top() == '(') { throw ParseException(START_BRACKET_PARSE_ERROR); }
			create_operation(keep_operator, keep_operand);
		}
		if (keep_operand.size() > 1) { throw ParseException(EXTRA_OPERAND_PARSE_ERROR); }
		return keep_operand.top();
	} 
	catch (const std::bad_alloc&) { deallocate(keep_operand); throw MemoryException(OVERFLOW_MEMORY_ERROR); }
	catch (...) { deallocate(keep_operand); throw; }
}