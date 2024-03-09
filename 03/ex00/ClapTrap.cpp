/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:36:04 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 00:19:59 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_health(10), m_energy(10), m_damage(0)
{
    std::cout << "Clap Trap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "Clap Trap " << copy.m_name << " copied!" << std::endl;
    operator=(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    this->m_name = rhs.m_name;
    this->m_health = rhs.m_health;
    this->m_energy = rhs.m_energy;
    this->m_damage = rhs.m_damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Clap Trap " << m_name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!checkAbility("attack!"))
        return ;
    m_energy--;
    std::cout << "ClapTrap " << m_name << " attacks "
    << target << " causing " << m_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    m_health -= amount;

    std::cout << "ClapTrap " << m_name << " takes  "
    << amount << " of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!checkAbility("be repaired!"))
        return ;
    m_energy--;
    m_health += amount;
    std::cout << "ClapTrap " << m_name << " repaired by "
    << amount << " to " << m_health << "!" << std::endl;
}

const std::string ClapTrap::getName() const
{
    return (m_name);
}

bool ClapTrap::checkAbility(const std::string origin) const
{
    if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << " has insufficient energy to " << origin << std::endl;
    if (m_health <= 0)
        std::cout << "ClapTrap " << m_name << " is too damaged to " << origin << std::endl;
    return (m_energy > 0 && m_health > 0);
}