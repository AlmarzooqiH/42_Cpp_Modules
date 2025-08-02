/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:36:42 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/02 18:31:21 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Defualt Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Deconstructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string animalType){
	std::cout << "WrongAnimal Type Constructor" << std::endl;
	this->type = animalType;
}

WrongAnimal::WrongAnimal(const WrongAnimal& right){
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	this->type = right.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& right){
	std::cout << "WrongAnimal Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const{
	std::cout << this->type << ": WrongAnimal Noises!!!" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (this->type);
}

void	WrongAnimal::setType(const std::string newType){
	this->type = newType;
}
