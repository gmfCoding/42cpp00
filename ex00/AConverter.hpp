#ifndef ACONVERTER_HPP
#define ACONVERTER_HPP
#include <string>

enum LiteralType
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
};

class AConverter
{
public:
	virtual bool match(const std::string& literal) = 0;
	virtual const std::string& getTypeName() = 0;
	virtual const std::string convert(const std::string& literal) = 0;
	virtual void print()
};
#endif
