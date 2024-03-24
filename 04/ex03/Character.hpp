/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:15:19 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 01:24:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class AMateria;
class Character : public ICharacter
{
	AMateria* slots[4];
	static const int len = sizeof(slots) / sizeof(*slots);

private:
	std::string name;

public:
	Character(const std::string& name);
	Character(const Character &copy);
	Character& operator=(const Character& rhs);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif