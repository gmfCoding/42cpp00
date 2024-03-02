/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:59:48 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:23:05 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

std::ostream& operator <<(std::ostream& os, const Point& rhs)
{
    return (os << "(" << rhs.x << ", " << rhs.y << ")");
}

Point& Point::operator=(const Point& rhs)
{
    // Do nothing, const fixed x,y are impossible to assign with UB
    (void)rhs;
    return *this;
}

Point Point::operator-(const Point& rhs) const
{
    return Point((this->x - rhs.x).toFloat(), (this->y - rhs.y).toFloat());
}

Point::~Point() {}

float Point::Det(const Point other) const
{
    return (other.x.toFloat() * this->x.toFloat() - other.y.toFloat() * this->y.toFloat());
}