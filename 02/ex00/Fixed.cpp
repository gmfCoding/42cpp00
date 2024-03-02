/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:09:29 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:09:30 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator =(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}