#include "Contact.hpp"

Contact::Contact():	m_first(""),
			m_last(""),
			m_nickname(""),
			m_number(""),
			m_secret("")
{

}

Contact::Contact(std::string first, 
			std::string last,
			std::string nickname, 
			std::string number,
			std::string secret):
			m_first(first),
			m_last(last),
			m_nickname(nickname),
			m_number(number),
			m_secret(secret)
{

}

std::string Contact::GetFirstName()
{
	return (this->m_first);
}

std::string Contact::GetLastName()
{
	return (this->m_last);
}

std::string Contact::GetNickName()
{
	return (this->m_nickname);
}

std::string Contact::GetNumber()
{
	return (this->m_number);
}

std::string Contact::GetSecret()
{
	return (this->m_secret);
}

