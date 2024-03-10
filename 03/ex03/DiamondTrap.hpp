/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:59 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 19:53:48 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string m_name;
protected:
    DiamondTrap(const std::string &name, const std::string &type);
    virtual void init(const std::string &type);


public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap &rhs);
    ~DiamondTrap();
    virtual const std::string getName() const;
    virtual const std::string getType() const;
    void attack(const std::string& target);
    void takeDamage(int amount);

    virtual int getHealth() const;
    virtual void setHealth(int health);

    virtual int getEnergy() const;
    virtual void setEnergy(int health);

    virtual int getDamage() const;
    virtual void setDamage(int health);

    void whoAmI(void);
};
#endif