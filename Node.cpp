#include "Node.h"
#include "Operators.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

NumberNode::NumberNode(int number) : number_(number), numberStr_(std::to_string(number)) {}
OperationNode::OperationNode(Node* left, Node* right) : left_(left), right_(right) {}

Type OperationNode::get_type() const { return Type::OPERATION; };
Type NumberNode::get_type() const { return Type::NUMBER; };

char AdditionNode::get_character() const { return ADDITION_SIGN; };
char SubtractionNode::get_character() const { return SUBTRACTION_SIGN; };
char MultiplicationNode::get_character() const { return MULTIPLICATION_SIGN; };
char DivisionNode::get_character() const { return DIVISION_SIGN; };

int NumberNode::eval() const { return number_; }
int AdditionNode::eval() const { return left_->eval() + right_->eval(); }
int SubtractionNode::eval() const { return left_->eval() - right_->eval(); }
int MultiplicationNode::eval() const { return left_->eval() * right_->eval(); }
int DivisionNode::eval() const { 
	int right = right_->eval();
	if ((right) == 0) { throw EvaluationException(ZERO_DIVISION_EVAL_ERROR); }
	return left_->eval() / right_->eval(); 
}

void NumberNode::postfix(std::ostream& stream) const { stream << numberStr_; }
void OperationNode::postfix(std::ostream& stream) const { 
	left_->postfix(stream); 
	stream << SPACE; 
	right_->postfix(stream); 
	stream << SPACE << get_character();
}

void NumberNode::infix(std::ostream& stream) const { stream << numberStr_; }
void OperationNode::infix(std::ostream& stream) const {
	if (left_->get_type() == Type::OPERATION) {
		if (Operators::get_precedence(((OperationNode*)left_)->get_character()) < Operators::get_precedence(get_character())) {
			stream << OPEN_BRACKET; 
			left_->infix(stream); 
			stream << CLOSE_BRACKET;
		} else { left_->infix(stream); }
	}
	else { left_->infix(stream); }
	stream << get_character();
	if (right_->get_type() == Type::OPERATION) {
		if (Operators::get_precedence(((OperationNode*)right_)->get_character()) <= Operators::get_precedence(get_character())) {
			stream << OPEN_BRACKET;
			right_->infix(stream); 
			stream << CLOSE_BRACKET;
		} else { right_->infix(stream); }
	}
	else { right_->infix(stream); }
}

Node::~Node() {}

OperationNode::~OperationNode() {
	if (left_ != nullptr) {
		delete left_;
		left_ = nullptr;
	}
	if (right_ != nullptr) {
		delete right_;
		right_ = nullptr;
	}
};