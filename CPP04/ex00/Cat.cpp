/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:03:43 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 21:03:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "Cat Defualt Constructor" << std::endl;
}

Cat::Cat(const std::string animalType): Animal(animalType){
	std::cout << "Cat Type Constructor" << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat Deconstructor" << std::endl;
}

Cat::Cat(const Cat& right): Animal(right){
	std::cout << "Cat Copy Constructor" << std::endl;
	this->type = right.type;
}

Cat& Cat::operator=(const Cat& right){
	std::cout << "Cat Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << this->type << ": Meow Meow" << std::endl;
}
