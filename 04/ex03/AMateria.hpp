/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:25:24 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 01:03:30 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class ICharacter;
class AMateria
{
protected:
	std::string type;

public:
	AMateria(std::string const & type);

	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& rhs);
	virtual ~AMateria();

	//Returns the materia type
	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};
#endif