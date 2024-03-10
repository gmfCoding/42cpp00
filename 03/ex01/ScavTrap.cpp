/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:44:03 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 18:43:42 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
    if (!checkHealth("enter Gate keeper mode!"))
        return ;
    std::cout << getType() << " " << m_name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::init(const std::string &type)
{
    m_type = type;
    m_health = 100;
    m_energy = 50;
    m_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, "ScavTrap")
{ 
    init("ScavTrap");
}

ScavTrap::ScavTrap(const std::string &name, const std::string &type) : ClapTrap(name, type)
{ 
    init(type);
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    this->m_type = obj.m_type;
    this->m_health = obj.m_health;
    this->m_name = obj.m_name;
    this->m_energy = obj.m_energy;
    this->m_damage = obj.m_damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this == &rhs)
		return *this;
    ClapTrap::operator=(rhs);
    return *this;
}

ScavTrap::~ScavTrap()
{
    
}