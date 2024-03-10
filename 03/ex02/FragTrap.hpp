/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:59 by clovell           #+#    #+#             */
/*   Updated: 2024/03/10 18:31:02 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

protected:
    FragTrap(const std::string &name, const std::string &type);
    virtual void init(const std::string &type);

public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &obj);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap();

    void highFivesGuys(void);
};
#endif