/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:28:27 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 18:39:02 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
    
protected:
    std::string m_name;
    int         m_health;
    int         m_energy;
    int         m_damage;
    
protected:
    std::string m_type;
    ClapTrap(const std::string &name, const std::string &type);
    virtual void init(const std::string &type);

public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& rhs);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    const std::string getName() const;
    int getDamage() const;
    
    virtual const std::string getType() const;

    bool canAct() const;

    bool checkHealthEnergy(const std::string origin) const;
    bool checkEnergy(const std::string origin) const;
    bool checkHealth(const std::string origin) const;
};
#endif