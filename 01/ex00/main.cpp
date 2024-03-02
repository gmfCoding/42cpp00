/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:11:35 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:11:37 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int main(void)
{
	Zombie* nz = newZombie("Fred");

	nz->announce();
	randomChump("John");
	delete nz;
	return (0);
}