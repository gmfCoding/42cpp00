/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:12:48 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:12:49 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"


Weapon::Weapon(const std::string& _type) : type(_type)
{

}

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
