/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:05:29 by hamad             #+#    #+#             */
/*   Updated: 2025/03/20 15:21:31 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->n = 0;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->n = f.n;
	this->setRawBits(f.getRawBits());
}
Fixed& Fixed::operator=(const Fixed& f){
	std::cout << "Copy assignment operator called" << std::endl;
	this->n = f.getRawBits();	
	return (*this);
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	this->n = 0;
}
void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->n = raw;
}
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->n);
}