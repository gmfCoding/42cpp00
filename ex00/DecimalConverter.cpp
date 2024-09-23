#include "DecimalConverter.hpp"
#include <iomanip>
#include <sstream>

DecimalConverter::DecimalConverter(const std::string& name, const char suffix) : m_name(name), m_suffix(suffix)
{ }

DecimalConverter::DecimalConverter() : m_name("DecimalConverter"), m_suffix('f')
{ }

DecimalConverter::~DecimalConverter()
{ }

bool DecimalConverter::match(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	char* ptr;
	strtof(literal.c_str(), &ptr);
	return ptr[0] == '\0' || ((ptr[0] == 'f' || ptr[0] == 'd') && ptr[1] == '\0');
}

const std::string DecimalConverter::convert(const std::string& literal)
{
	if (literal.empty())
		return "impossible";
	
	char* ptr;
	double value = strtod(literal.c_str(), &ptr);
	std::string result;

	if (!(ptr[0] == '\0' || ((ptr[0] == 'f' || ptr[0] == 'd') && ptr[1] == '\0')))
		return "impossible";
	if (value < 0.0)
		result += "-";
	if (isinf(value))
		result += "inf";
	if (isnan(value))
		result += "nan";
	else
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(2) << value << std::flush;
		result += ss.str();
		result += m_suffix;
	}
	return result;
}
const std::string& DecimalConverter::getTypeName()
{
	return m_name;
}

