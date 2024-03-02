/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:38 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:38 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon* weapon;
	std::string name;
	
	public:
	HumanB(const std::string& _name);

	void setWeapon(Weapon& weapon);
	void attack();
};

#endif
