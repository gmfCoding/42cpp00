#include "Data.hpp"

Data::Data(int number, bool active, float percent, char character, std::string text) :
	m_number(number),
	m_active(active),
	m_percent(percent),
	m_character(character),
	m_text(text)
{

}

Data::Data(Data& copy)
{
	if (this != &copy)
		return (*this);
	this->operator=(copy);
	return (*this);
}

Data& Data::operator=(Data& rhs)
{
	this->m_number = rhs.m_number;
	this->m_active = rhs.m_active;
	this->m_percent = rhs.m_percent;
	this->m_character = rhs.m_character;
	this->m_text = rhs.m_text;
}

std::ostream& Data::operator<<(std::ostream& out)
{
	out << "Instance Address: " << this << std::endl;
	out << "number:\t" << this->m_number << std::endl;
	out << "active:\t" << this->m_active << std::endl;
	out << "percent:\t" << this->m_percent << std::endl;
	out << "character:\t" << this->m_character << std::endl;
	out << "text:\t\t" << this->m_text << std::endl;
}

~Data::Data()
{

}
