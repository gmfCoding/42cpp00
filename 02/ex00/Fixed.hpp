/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:03:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int					value;
	static const int	frac = 8;

	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator =(const Fixed& rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
#endif