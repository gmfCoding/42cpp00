/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:54 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 20:09:41 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	AAnimal& operator=(const AAnimal& rhs);
	virtual ~AAnimal() = 0;
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif