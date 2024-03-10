/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:44:03 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 18:45:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
    if (!checkHealthEnergy("ask for a high five!"))
        return ;
    std::cout << getType() << " " << getName();
    std::cout << " really wants a high five!" << std::endl;
}

void FragTrap::init(const std::string &type)
{
    m_type = type;
    m_health = 100;
    m_energy = 100;
    m_damage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, "FragTrap")
{ 
    init("FragTrap");
}

FragTrap::FragTrap(const std::string &name, const std::string &type) : ClapTrap(name, type)
{ 
    init(type);
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    this->m_type = obj.m_type;
    this->m_health = obj.m_health;
    this->m_name = obj.m_name;
    this->m_energy = obj.m_energy;
    this->m_damage = obj.m_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this == &rhs)
		return *this;
    ClapTrap::operator=(rhs);
    return *this;
}

FragTrap::~FragTrap()
{
    
}