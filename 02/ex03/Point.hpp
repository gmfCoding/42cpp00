/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:59:40 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:21:33 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
class Point
{
	private:
	Fixed const x;
	Fixed const y;

	public:
	Point();
	Point(const float x, const float y);
	Point(const Point& copy);
	~Point();

	Point& operator =(const Point& rhs);
	Point operator -(const Point& rhs) const;
	
	friend std::ostream& operator <<(std::ostream& os, const Point& rhs);
	
	float Det(const Point other) const;

	void SetFixedX(const Fixed x);
	void SetFixedY(const Fixed Y);
};
#endif