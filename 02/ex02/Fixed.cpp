#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const float num)
{
    setRawBits(round(num * (1 << frac)));
}

Fixed::Fixed(const int num)
{
    setRawBits(num << frac);
}

Fixed::Fixed(const Fixed& copy)
{
    *this = copy;
}

Fixed::~Fixed()
{

}


Fixed& Fixed::operator =(const Fixed& rhs)
{
    this->setRawBits(rhs.getRawBits());
    return (*this);
}

std::ostream& operator <<(std::ostream& os, const Fixed& rhs)
{
    return (os << rhs.toFloat());
}

bool Fixed::operator <(const Fixed& rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator >(const Fixed& rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator <=(const Fixed& rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator >=(const Fixed& rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator ==(const Fixed& rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator !=(const Fixed& rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator *(const Fixed& rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator /(const Fixed& rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator +(const Fixed& rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator -(const Fixed& rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

// ++rhs
Fixed& Fixed::operator ++(void)
{
    this->value++;
    return (*this);
}

// --rhs
Fixed& Fixed::operator --(void)
{
    this->value--;
    return (*this);
}

// lhs++
Fixed Fixed::operator ++( int )
{
	Fixed	temp = *this;
	this->value++;
	return (temp);
}

// lhs--
Fixed Fixed::operator --( int )
{
	Fixed	temp = *this;
	this->value--;
	return (temp);
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

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs < rhs)
        return (lhs);
    return (rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    if (lhs > rhs)
        return (lhs);
    return (rhs);
}