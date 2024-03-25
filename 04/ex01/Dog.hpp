/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:58:54 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 18:15:19 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog &copy);
	Dog& operator=(const Dog& rhs);
	~Dog() ;

	void makeSound() const;

	bool isDeepCopy(const Dog* other) const;
};

#endif