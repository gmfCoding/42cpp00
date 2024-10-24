#include "RPNParser.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPNParser::RPNParser()
{ }

RPNParser::RPNParser(const std::string& input)
{ 
	std::stringstream stream;
	stream << input;
	std::string buffer;
	while (stream.good() && !stream.eof())
	{
		getline(stream, buffer, ' ');

		if (buffer.size() == 0)
			continue;
		if (buffer.size() == 1)
		{
			char op = buffer[0];
			bool wasOp = true;
			switch (op)
			{
			case '*':
				tokens.push(Token(buffer, MUL));
				break;
			case '+':
				tokens.push(Token(buffer, ADD));
				break;
			case '-':
				tokens.push(Token(buffer, SUB));
				break;
			case '/':
				tokens.push(Token(buffer, DIV));
				break;
			default:
				wasOp = false;
				break;
			}
			if (wasOp == false)
				tokens.push(Token(buffer, op - '0'));
		}
		else
		{
			int value = atoi(buffer.c_str());
			tokens.push(Token(buffer, value));
		}
	}
	std::stack<Token> literals;
	for (;tokens.size() != 0;)
	{
		Token token = tokens.front();
		tokens.pop();

		if (token.type == LITERAL)
			literals.push(token);
		else if (literals.size() <= 1)
		{
			std::cerr << "Error" << std::endl;
			return; 
		}
		else
		{
			Token rhs = literals.top();
			literals.pop();
			Token lhs = literals.top();
			literals.pop();
			switch (token.u.operation)
			{
			case MUL:
				literals.push(Token(lhs.string + token.string + rhs.string, lhs.u.value * rhs.u.value));
				break;
			case ADD:
				literals.push(Token(lhs.string + token.string + rhs.string, lhs.u.value + rhs.u.value));
				break;
			case SUB:
				literals.push(Token(lhs.string + token.string + rhs.string, lhs.u.value - rhs.u.value));
				break;
			case DIV:
				literals.push(Token(lhs.string + token.string + rhs.string, lhs.u.value / rhs.u.value));
				break;
			default:
				break;
			}

		}
	}
	if (literals.size() >= 2)
		std::cerr << "Error: missing operator" << std::endl;
	if (tokens.size() >= 1)
		std::cerr << "Error: missing literal" << std::endl;

	std::cout << literals.top().u.value << std::endl;
}

RPNParser::RPNParser(const RPNParser& copy)
{
	(void)copy;
}

// Assignment operator
RPNParser& RPNParser::operator=(const RPNParser& rhs)
{
	// Check for self-assignment
	if (this == &rhs)
		return *this;

	return *this;
}

// Destructor
RPNParser::~RPNParser()
{ }
