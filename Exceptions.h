#ifndef EXCEPT_H
#define EXCEPT_H

class Exception {
protected:
	const char* message_;
public:
	Exception(const char* message);
	const char* message() const;
};

class EvaluationException : public Exception {
	using Exception::Exception;
};

class ParseException : public Exception {
	using Exception::Exception;
};

class MemoryException : public Exception {
	using Exception::Exception;
};

inline const char* Exception::message() const { return message_; }

#endif