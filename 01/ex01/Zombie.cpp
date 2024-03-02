/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:04 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::SetName(const std::string& str)
{
	name = str;
}

Zombie::Zombie(const std::string& str) : name(str)
{

}

Zombie::~Zombie()
{
	std::cout << "Zombie Killed:" << this->name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

