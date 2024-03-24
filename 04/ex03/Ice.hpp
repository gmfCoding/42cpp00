/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:25:24 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 00:40:37 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();

	Ice(const Ice& copy);
	Ice& operator=(const Ice& rhs);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};
#endif