/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:25:24 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 20:26:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();

	Cure(const Cure& copy);
	Cure& operator=(const Cure& rhs);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};
#endif