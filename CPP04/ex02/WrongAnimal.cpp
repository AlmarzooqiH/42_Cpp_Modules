/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:36:42 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/15 10:54:21 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal defualt constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal deconstructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string animalType){
	this->type = animalType;
}

WrongAnimal::WrongAnimal(const WrongAnimal& right){
	std::cout << "WrongAnimal copy constructor" << std::endl;
	this->type = right.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& right){

	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal Noises!!!" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (this->type);
}

void	WrongAnimal::setType(const std::string newType){
	this->type = newType;
}
