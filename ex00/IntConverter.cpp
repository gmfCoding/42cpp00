#include "IntConverter.hpp"
#include <iomanip>
#include <sstream>

IntConverter::IntConverter(const std::string& name, const char suffix) : m_name(name), m_suffix(suffix)
{ }

IntConverter::IntConverter() : m_name("IntConverter"), m_suffix('f')
{ }

IntConverter::~IntConverter()
{ }

bool IntConverter::match(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	return !(isalpha(literal[0]) || (literal.length() > 1 && isalpha(literal[1]));
}

const std::string IntConverter::convert(const std::string& literal)
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
const std::string& IntConverter::getTypeName()
{
	return m_name;
}

