#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>

enum TokenType
{
	LITERAL,
	OPERATION
};

enum Operation
{
	ADD,
	SUB,
	MUL,
	DIV
};

struct Token
{
public:
	std::string	string;
	TokenType	type;

	union tun {
		Operation operation;
		int value;
	} u;

	Token(std::string content, int value);
	Token(std::string content, Operation op);

	Token(const Token& copy);
	Token& operator=(const Token& rhs);
	virtual ~Token();

};
#endif // TOKEN_HPP
