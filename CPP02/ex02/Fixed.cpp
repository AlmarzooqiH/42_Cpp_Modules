/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:05:29 by hamad             #+#    #+#             */
/*   Updated: 2025/07/13 10:44:23 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed& f)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->rawBits = f.rawBits;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = i << bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(f * (1 << this->bits));
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->rawBits = other.getRawBits();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	this->rawBits = 0;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}

float	Fixed::toFloat(void) const {
	return ((((float)this->rawBits) / (1 << this->bits)));
}

int		Fixed::toInt(void) const {
	return (this->rawBits >> bits);
}

bool	Fixed::operator>(const Fixed& f){
	return (this->rawBits > f.getRawBits());
}

bool	Fixed::operator<(const Fixed& f){
	return (this->rawBits < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f){
	return (this->rawBits >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f){
	return (this->rawBits <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed& f){
	return (this->rawBits == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f){
	return (this->rawBits != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f){
	return (Fixed(this->rawBits + f.getRawBits()));
}

Fixed	Fixed::operator-(const Fixed& f){
	return (Fixed(this->rawBits - f.getRawBits()));
}

Fixed	Fixed::operator*(const Fixed& f){
	return (Fixed(toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& f){
	if (f.getRawBits() == 0)
	{
		std::cout << "Cannot divide by 0" << std::endl;
		return Fixed(0);
	}
	return (Fixed(toFloat() / f.toFloat()));
}

//Post increment
Fixed	Fixed::operator++(int){
	Fixed old = *this;
	this->rawBits++;
	return (old);
}
//Pre increment
Fixed&	Fixed::operator++(){
	this->rawBits++;
	return (*this);
}
//Post decrement
Fixed	Fixed::operator--(int){
	Fixed old = *this;
	this->rawBits--;
	return (old);
}
//Pre Decrement
Fixed&	Fixed::operator--(){
	this->rawBits--;
	return (*this);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b){
	return ((a < b) ? a : b);
}
const Fixed&	Fixed::min(const Fixed &a, const Fixed &b){
	return ((a.getRawBits() < b.getRawBits()) ? a : b);
}
Fixed&	Fixed::max(Fixed &a, Fixed &b){
	return ((a > b) ? a : b);
}
const Fixed&	Fixed::max(const Fixed &a, const Fixed &b){
	return ((a.getRawBits() > b.getRawBits()) ? a : b);

}
