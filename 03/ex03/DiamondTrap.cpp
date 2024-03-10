/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:44:03 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 19:58:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "DiamondTrap.hpp"

void DiamondTrap::init(const std::string &type)
{
    ScavTrap::m_type = type;
    FragTrap::m_type = type;
}

int DiamondTrap::getHealth() const
{
    return (FragTrap::getHealth());
}

void DiamondTrap::setHealth(int health)
{
    ScavTrap::setHealth(health);
}

int DiamondTrap::getEnergy() const
{
    return (ScavTrap::getEnergy());
}

void DiamondTrap::setEnergy(int energy)
{
    ScavTrap::setEnergy(energy);
}

int DiamondTrap::getDamage() const
{
    return (FragTrap::getDamage());
}

void DiamondTrap::setDamage(int damage)
{
    FragTrap::setDamage(damage);
}

const std::string DiamondTrap::getName() const
{
    return (DiamondTrap::m_name);
}


const std::string DiamondTrap::getType() const
{
    return (ScavTrap::getType());
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(int amount)
{
    FragTrap::takeDamage(amount);
}

DiamondTrap::DiamondTrap(const std::string &name) : ScavTrap(name + "_clap_name", "DiamondTrap"), FragTrap(name + "_clap_name", "DiamondTrap"), m_name(name)
{ 
    init("DiamondTrap");
    std::cout << "DiamondTrap" << " " << name << " created!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name, const std::string &type) : ScavTrap(name + "_clap_name", type), FragTrap(name + "_clap_name", type), m_name(name)
{ 
    init(type);
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ScavTrap(obj), FragTrap(obj)
{
    this->setHealth(obj.getHealth());
    this->setEnergy(obj.getEnergy());
    this->setDamage(obj.getDamage());
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this == &rhs)
		return *this;
    ScavTrap::operator=(rhs);
    FragTrap::operator=(rhs);
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << getType() << " " << getName() << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << getType() << "my name is: " << getName() << "my ClapTrap name is: " << FragTrap::getName() << std::endl;
}