/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:52:54 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 19:52:54 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
	std::cout << "Animal defualt constructor" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal deconstructor" << std::endl;
}

Animal::Animal(const std::string animalType){
	this->type = animalType;
}

Animal::Animal(const Animal& right){
	std::cout << "Animal copy constructor" << std::endl;
	this->type = right.type;
}

Animal&	Animal::operator=(const Animal& right){

	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

std::string	Animal::getType() const{
	return (this->type);
}

void	Animal::setType(const std::string newType){
	this->type = newType;
}
