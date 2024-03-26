/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:45 by clovell           #+#    #+#             */
/*   Updated: 2024/03/26 14:47:01 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	static const int	len = 4;
	AMateria			*slots[len];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
};
#endif