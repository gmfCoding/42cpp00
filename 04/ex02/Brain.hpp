#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain
{
private:
	const static int ideas_count = 100;
	std::string ideas[ideas_count];

public:
	Brain();
	Brain(const Brain &copy);
	Brain& operator=(const Brain& rhs);
	~Brain();
};

#endif