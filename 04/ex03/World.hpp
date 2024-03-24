#include "AMateria.hpp"

class World
{
	static World world;
	AMateria**	dropped;
	unsigned int			capacity;
	unsigned int			count;

public:
	World(unsigned int capacity);
	void	drop(AMateria* &mat);
	static World&	get(void);

private:
	~World();
	World(const World &copy);
	World& operator=(const World& rhs);
	void resize(void);
};

