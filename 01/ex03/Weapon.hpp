/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:53 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:55 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class Weapon
{
	private:
	std::string type;

	public:
	Weapon(const std::string& _type);

	const std::string& getType();
	void setType(const std::string& type);
};

#endif
