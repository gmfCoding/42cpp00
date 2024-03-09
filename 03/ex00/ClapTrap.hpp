/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:28:27 by clovell           #+#    #+#             */
/*   Updated: 2024/03/09 18:34:56 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string>

class ClapTrap
{
private:
    /* data */
    std::string m_name;
    int m_health;
    int m_energy;
    int m_damage;

public:
    ClapTrap(const std::string &name);
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& rhs);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_health(10), m_energy(10), m_damage(0)
{
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    operator=(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    this->m_name = rhs.m_name;
    this->m_health = rhs.m_health;
    this->m_energy = rhs.m_energy;
    this->m_damage = rhs.m_damage;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
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
    m_health -= amount;

    std::cout << "ClapTrap " << m_name << " repaired by "
    << amount << " to " << m_health << "!" << std::endl;
}

