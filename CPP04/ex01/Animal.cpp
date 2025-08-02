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
	std::cout << "Animal Defualt Constructor" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal Deconstructor" << std::endl;
}

Animal::Animal(const std::string animalType){
	std::cout << "Animal Type Constructor" << std::endl;
	this->type = animalType;
}

Animal::Animal(const Animal& right){
	std::cout << "Animal Copy Constructor" << std::endl;
	this->type = right.type;
}

Animal&	Animal::operator=(const Animal& right){
	std::cout << "Animal Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	Animal::makeSound() const{
	std::cout << this->type << ": Animal Noises!!!" << std::endl;
}

std::string	Animal::getType() const{
	return (this->type);
}

void	Animal::setType(const std::string newType){
	this->type = newType;
}
