#ifndef CONST_H
#define CONST_H

enum class Type { NUMBER, OPERATION };
enum class Child { LEFT, RIGHT, ROOT };

constexpr char ADDITION_SIGN = '+';
constexpr char SUBTRACTION_SIGN = '-';
constexpr char MULTIPLICATION_SIGN = '*';
constexpr char DIVISION_SIGN = '/';

constexpr char SPACE = ' ';
constexpr char CHAR_ZERO = '0';

constexpr char OPEN_BRACKET = '(';
constexpr char CLOSE_BRACKET = ')';

constexpr int PRECEDENCE_ERROR = -1;
constexpr int LOW_PRECEDENCE = 1;
constexpr int HIGH_PRECEDENCE = 2;
constexpr int NUMBER_BASE = 10;

constexpr char UNKNOWN_PARSE_ERROR[] = "Unknown token";
constexpr char OVERFLOW_PARSE_ERROR[] = "Overflow number";
constexpr char MISSING_OPERAND_PARSE_ERROR[] = "Missing operands";
constexpr char END_BRACKET_PARSE_ERROR[] = "Unmatched closing parenthesis";
constexpr char START_BRACKET_PARSE_ERROR[] = "Unmatched opening parenthesis";
constexpr char EXTRA_OPERAND_PARSE_ERROR[] = "Unused operands";
constexpr char VOID_PARSE_ERROR[] = "Empty expression";

constexpr char OVERFLOW_MEMORY_ERROR[] = "Unavailable memory";

constexpr char ZERO_DIVISION_EVAL_ERROR[] = "Division by zero";

#endif
