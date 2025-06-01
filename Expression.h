#ifndef EXPRESS_H
#define EXPRESS_H
#include "Node.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

class Expression {
private:
	Node* root_ = nullptr;
public:
	Expression(Node* root);
	Expression(const std::string& input);
	void print_postfix(std::ostream& stream = std::cout) const;
	void print_infix(std::ostream& stream = std::cout) const;
	int evaluate() const;
	~Expression();
};

#endif
