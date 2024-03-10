/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:59 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 18:02:50 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

protected:
    ScavTrap(const std::string &name, const std::string &type);
    virtual void init(const std::string &type);

public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &obj);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap();

    void guardGate();
};
#endif