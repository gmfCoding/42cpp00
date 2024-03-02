/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:13:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:13:30 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HARL_HPP
# define HARL_HPP
#include <string>

class Harl
{
	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	public:
	void complain(std::string level);
	void complainfrom(std::string level);
};

#endif
