/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:02:55 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
	private:
	int					value;
	static const int	frac = 8;

	public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float decimal);
	Fixed(const Fixed& copy);
	Fixed& operator =(const Fixed& rhs);
	friend std::ostream& operator <<(std::ostream& os, const Fixed& rhs);

	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
#endif