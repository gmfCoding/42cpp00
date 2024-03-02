/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:09 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:09 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
