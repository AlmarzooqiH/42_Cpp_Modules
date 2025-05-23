/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:05:29 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 22:33:51 by hamalmar         ###   ########.fr       */
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
Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = other.getRawBits();	
	return (*this);
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