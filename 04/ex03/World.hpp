/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:07:08 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 20:28:20 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WORLD_HPP
# define WORLD_HPP
#include "AMateria.hpp"

class World
{
	static World world;
	AMateria**	dropped;
	unsigned int			capacity;
	unsigned int			count;

public:
	World();
	World(unsigned int capacity);
	void	drop(AMateria* &mat);
	static World&	get(void);

private:
	~World();
	World(const World &copy);
	World& operator=(const World& rhs);
	void resize(void);
};
#endif