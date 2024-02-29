#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	private:
	std::string name;

	public:
	Zombie();
	Zombie(const std::string& str);
	~Zombie();

	void SetName(const std::string& str);
	void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
#endif
