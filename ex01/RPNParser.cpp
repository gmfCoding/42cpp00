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
			if (!wasOp && !isdigit(op))
			{
				throw std::runtime_error("Error");
			}
			if (!wasOp)
				tokens.push(Token(buffer, op - '0'));
		}
		else
		{
			if (std::isdigit(buffer[0]) == false)
				throw std::runtime_error("Error");
			char* p;
			long value = strtol(buffer.c_str(), &p, 10);
			if (*p) {
				throw std::runtime_error("Error");
			}
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
			throw std::runtime_error("Error");
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
				if (rhs.u.value == 0)
					throw std::runtime_error("Divide by zero not allowed.");
				literals.push(Token(lhs.string + token.string + rhs.string, lhs.u.value / rhs.u.value));
				break;
			default:
				break;
			}

		}
	}
	if (literals.size() >= 2)
		throw std::runtime_error("Error: missing operator");
	if (tokens.size() >= 1)
		throw std::runtime_error("Error: missing operator");

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
