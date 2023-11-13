#ifndef CONTACT_H
# define CONTACT_H
#include <string>

class Contact
{
	std::string	m_first;
	std::string	m_last;
	std::string	m_nickname;
	std::string	m_number;
	std::string	m_secret;

	public:

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetNumber();
	std::string GetSecret();

	Contact();
	Contact(std::string first, 
			std::string last,
			std::string nickname, 
			std::string number,
			std::string secret);
};
#endif
