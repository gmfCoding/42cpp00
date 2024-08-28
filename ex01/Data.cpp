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
	this->operator=(copy);
}

Data& Data::operator=(Data& rhs)
{
	if (this != &rhs)
		return (*this);
	this->m_number = rhs.m_number;
	this->m_active = rhs.m_active;
	this->m_percent = rhs.m_percent;
	this->m_character = rhs.m_character;
	this->m_text = rhs.m_text;
	return (*this);
}

std::ostream& operator<< (std::ostream& out, const Data& data)
{
	out << "Instance Address: " << &data << std::endl;
	out << "number:\t" << data.m_number << std::endl;
	out << "active:\t" << data.m_active << std::endl;
	out << "percent:\t" << data.m_percent << std::endl;
	out << "character:\t" << data.m_character << std::endl;
	out << "text:\t\t" << data.m_text << std::endl;
	return out;
}

Data::~Data()
{

}
