/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:05:29 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 22:59:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = 0;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = f.rawBits;
	this->rawBits = f.rawBits;
}

Fixed::Fixed(const int i)
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = i << bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Default constructor called" << std::endl;
	this->rawBits = f * (1 << this->bits);
}
Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = other.rawBits;	
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
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

float	Fixed::toFloat(void) const {return (this->rawBits / (1 << this->bits));}
int		Fixed::toInt(void) const {return (this->rawBits >> bits);}