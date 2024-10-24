#include "Token.hpp"

Token::Token(std::string content, int value) : string(content), type(LITERAL)
{
	u.value = value;
}

Token::Token(std::string content, Operation op): string(content), type(OPERATION)
{
	u.operation = op;
}

Token::Token(const Token& copy): string(copy.string), type(copy.type), u(copy.u)
{

}
Token& Token::operator=(const Token& rhs)
{
	// Check for self-assignment
	if (this == &rhs)
		return *this;

	return *this;
}

Token::~Token()
{ }
