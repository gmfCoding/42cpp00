/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:28:27 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 00:09:19 by clovell          ###   ########.fr       */
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
    ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& rhs);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    const std::string getName() const;

    bool canAct() const;

    bool checkAbility(const std::string origin) const;
};