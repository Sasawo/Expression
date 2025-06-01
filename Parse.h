#ifndef PARSE_H
#define PARSE_H
#include "Node.h"
#include <string>
#include <stack>

class Parser {
private:
	inline static int ctoi(char chr);
	static void create_operation(std::stack<char>& optr, std::stack<Node*>& opnd);
	static void deallocate(std::stack<Node*>& opnd);
	static void deallocate(Node*& opnd);
	static int parse_digit(const std::string& input, const size_t length, unsigned int iterator, std::stack<Node*>& opnd);
	static void parse_op(const char index, std::stack<Node*>& opnd, std::stack<char>& optr);
	static void parse_bracket(std::stack<Node*>& opnd, std::stack<char>& optr);
	static void try_push(std::stack<Node*>& opnd, Node* node);
	static Node* parse_actual(const std::string& input);
public:
	static Node* parse(const std::string& input);
};

#endif