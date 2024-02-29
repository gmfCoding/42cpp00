#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(round(num * (1 << frac)));
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(num << frac);
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

std::ostream& operator <<(std::ostream& os, const Fixed& rhs)
{
    return (os << rhs.toFloat());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)getRawBits() / (float)(1 << frac));
}

int Fixed::toInt(void) const
{
    return (value >> frac);
}