/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:36:04 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 19:16:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : m_name(name)
{
    init("ClapTrap");
    std::cout << getType() << name << " created!" << std::endl;
}

void ClapTrap::init(const std::string &type)
{
    m_type = type;
    m_health = 10;
    m_energy = 10;
    m_damage = 0;
}

int ClapTrap::getHealth() const
{
    return (m_health);
}

void ClapTrap::setHealth(int health)
{
    this->m_health = health;
}

int ClapTrap::getEnergy() const
{
    return (m_energy);
}

void ClapTrap::setEnergy(int energy)
{
    m_energy = energy;
}

int ClapTrap::getDamage() const
{
    return (m_damage);
}

void ClapTrap::setDamage(int damage)
{
    m_damage = damage;
}

const std::string ClapTrap::getName() const
{
    return (m_name);
}

const std::string ClapTrap::getType() const
{
    return (m_type);
}

ClapTrap::ClapTrap(const std::string &name, const std::string &type) : m_name(name)
{
    init(type);
    std::cout << getType() << " " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << getType() << " " << copy.m_name << " copied!" << std::endl;
    operator=(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (this == &rhs)
		return *this;
    this->m_name = rhs.m_name;
    this->m_health = rhs.m_health;
    this->m_energy = rhs.m_energy;
    this->m_damage = rhs.m_damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << getType() << " " << getName() << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!checkHealthEnergy("attack!"))
        return ;
    setEnergy(getEnergy() - 1);
    std::cout << getType() << " " << getName() << " attacks "
    << target << " causing " << getDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    setHealth(getHealth() - amount);
    std::cout << getType() << " " << getName()  << " takes  "
    << amount << " of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!checkHealthEnergy("be repaired!"))
        return ;
    setEnergy(getEnergy() - 1);
    setHealth(getHealth() + amount);
    std::cout << getType() << " " << getName() << " repaired by "
    << amount << " to " << getHealth() << "!" << std::endl;
}

bool ClapTrap::checkHealthEnergy(const std::string origin) const
{
    return (checkEnergy(origin) && checkHealth(origin));
}

bool ClapTrap::checkEnergy(const std::string origin) const
{
    if (getEnergy() <= 0)
        std::cout << getType() << " " << m_name << " has insufficient energy to " << origin << std::endl;
    return (getEnergy() > 0);
}

bool ClapTrap::checkHealth(const std::string origin) const
{
    if (getHealth() <= 0)
        std::cout << getType() << " " << m_name << " is too damaged to " << origin << std::endl;
    return (getHealth() > 0);
}