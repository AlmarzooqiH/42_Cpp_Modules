/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:39:59 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 20:39:59 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << "Dog Defualt Constructor" << std::endl;
}

Dog::Dog(const std::string animalType): Animal(animalType){
	std::cout << "Cat Type Constructor" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog Deconstructor" << std::endl;
}

Dog::Dog(const Dog& right): Animal(right){
	std::cout << "Dog Copy Donstructor" << std::endl;
	this->type = right.type;
}

Dog& Dog::operator=(const Dog& right){
	std::cout << "Dog Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << this->type << ": Woof Woof" << std::endl;
}
