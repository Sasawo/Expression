#include "Expression.h"
#include "Parse.h"
#include <string>

Expression::~Expression() {
	if (root_ != nullptr) {
		delete root_;
		root_ = nullptr;
	}
};

Expression::Expression(Node* root) : root_(root) {};

Expression::Expression(const std::string& input) { 
	root_ = Parser::parse(input);
};

int Expression::evaluate() const {
	return root_->eval();
}

void Expression::print_infix(std::ostream& stream) const {
	root_->infix(stream);
}

void Expression::print_postfix(std::ostream& stream) const {
	root_->postfix(stream);
}
