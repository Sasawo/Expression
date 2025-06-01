/*int DivisionNode::eval() const {
	int rightResult = right_->eval();
	if (rightResult == 0) { throw EvaluationException(zeroDivisionError); }
	return left_->eval() / right_->eval();
}

int main() {
	try {
		Parse::parser("10*5+8-(3+5)*7");
	}
	catch (Exception e) { std::cout << e.message(); }
}*/