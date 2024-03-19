/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:54 by clovell           #+#    #+#             */
/*   Updated: 2024/03/19 23:22:29 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif