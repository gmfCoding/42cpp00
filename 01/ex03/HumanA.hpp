/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:30 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon& weapon;
	std::string name;
	
	public:
	HumanA(const std::string& _name, Weapon& _weapon);
	void attack();
};

#endif


