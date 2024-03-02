/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:00:29 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

	bool operator <(const Fixed& rhs) const;
	bool operator >(const Fixed& rhs) const;
	bool operator <=(const Fixed& rhs) const;
	bool operator >=(const Fixed& rhs) const;
	bool operator ==(const Fixed& rhs) const;
	bool operator !=(const Fixed& rhs) const;

	Fixed operator *(const Fixed& rhs) const;
	Fixed operator /(const Fixed& rhs) const;
	Fixed operator +(const Fixed& rhs) const;
	Fixed operator -(const Fixed& rhs) const;


	Fixed& operator --(void);
	Fixed& operator ++(void);
	Fixed operator --(int);
	Fixed operator ++(int);

	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
	static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

	friend std::ostream& operator <<(std::ostream& os, const Fixed& rhs);

	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(const int raw);
};