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
	this->dog_brain = new Brain();
}

Dog::Dog(const std::string animalType): Animal(animalType){
	std::cout << "Cat Type Constructor" << std::endl;
	this->dog_brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog Deconstructor" << std::endl;
	delete dog_brain;
}

Dog::Dog(const Dog& right): Animal(right){
	std::cout << "Dog Copy Constructor" << std::endl;
	this->type = right.type;
	this->dog_brain = new Brain(*right.dog_brain);
}

Dog& Dog::operator=(const Dog& right){
	std::cout << "Dog Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
		delete this->dog_brain;
		this->dog_brain = new Brain(*right.dog_brain);
	}
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << this->type << ": Woof Woof" << std::endl;
}

Brain& Dog::getBrain() const{return (*this->dog_brain);}