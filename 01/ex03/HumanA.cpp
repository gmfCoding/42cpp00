/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:25 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:26 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& _name, Weapon& _weapon) : weapon(_weapon), name(_name)
{

}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
   	std::cout << this->weapon.getType() << std::endl;
}
