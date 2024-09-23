#ifndef DATA_HPP
#define DATA_HPP
#include <string>
#include <ostream>

class Data
{
public:
	int m_number;
	bool m_active;
	float m_percent;	
	char m_character;
	std::string m_text;

public:	
	Data(int number, bool active, float percent, char character, std::string text);
	Data(Data& copy);
	Data& operator =(Data& rhs);
	~Data();
};

std::ostream& operator<< (std::ostream &out, const Data& b);
#endif