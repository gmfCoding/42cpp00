/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:00 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:00 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int main(void)
{
	int	size = 30;
	Zombie* undead = zombieHorde(size, "Benard");
	for (int i = 0; i < size; i++)
		undead[i].announce();
	delete[] undead;
	return (0);
}
