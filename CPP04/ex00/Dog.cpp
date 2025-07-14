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
	std::cout << "Dog defualt constructor" << std::endl;
}

Dog::Dog(const std::string animalType): Animal(animalType){
	std::cout << "Cat type constructor" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog deconstructor" << std::endl;
}

Dog::Dog(const Dog& right): Animal(right){
	std::cout << "Dog copy constructor" << std::endl;
	this->type = right.type;
}

Dog& Dog::operator=(const Dog& right){
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	Dog::makeSound(){
	std::cout << "Woof Woof" << std::endl;
}
