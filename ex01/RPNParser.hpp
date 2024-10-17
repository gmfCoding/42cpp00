#ifndef RPNPARSER_HPP
#define RPNPARSER_HPP
#include <queue>
#include <string>
#include "Token.hpp"

class RPNParser
{
	private:
	std::queue<Token> tokens;
	RPNParser();

public:
	RPNParser(const std::string& input);
	RPNParser(const RPNParser& copy);
	RPNParser& operator=(const RPNParser& rhs);
	virtual ~RPNParser();
};
#endif