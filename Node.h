#ifndef NODE_H
#define NODE_H
#include "Constants.h"
#include <string>

class Node {
public:
	virtual Type get_type() const = 0;
	virtual ~Node();
	virtual int eval() const = 0;
	virtual void postfix(std::ostream& stream) const = 0;
	virtual void infix(std::ostream& stream) const = 0;
};

class NumberNode final : public Node {
private:
	int number_;
	std::string numberStr_;
public:
	NumberNode(int number);
	Type get_type() const override;
	int eval() const override;
	void postfix(std::ostream& stream) const override;
	void infix(std::ostream& stream) const override;
};

class OperationNode : public Node {
protected:
	Node* left_;
	Node* right_;
public:
	OperationNode(Node* left, Node* right);
	void postfix(std::ostream& stream) const override;
	void infix(std::ostream& stream) const override;
	virtual char get_character() const = 0;
	Type get_type() const override;
	virtual ~OperationNode();
};

class AdditionNode final : public OperationNode {
public:
	using OperationNode::OperationNode;
	char get_character() const override;
	int eval() const override;
};

class SubtractionNode final : public OperationNode {
public:
	using OperationNode::OperationNode;
	char get_character() const override;
	int eval() const override;
};

class MultiplicationNode final : public OperationNode {
public:
	using OperationNode::OperationNode;
	char get_character() const override;
	int eval() const override;
};

class DivisionNode final : public OperationNode {
public:
	using OperationNode::OperationNode;
	char get_character() const override;
	int eval() const override;
};

#endif