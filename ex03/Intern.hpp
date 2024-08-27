/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:46:17 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:46:22 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{

public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(Intern& rhs);
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};

#endif
