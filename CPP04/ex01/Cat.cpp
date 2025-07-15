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
	std::cout << "Cat defualt constructor" << std::endl;
	this->car_brain = new Brain();
}

Cat::Cat(const std::string animalType): Animal(animalType){
	std::cout << "Cat type constructor" << std::endl;
	this->car_brain = new Brain();
}

Cat::~Cat(){
    std::cout << "Cat deconstructor" << std::endl;
	delete car_brain;
}

Cat::Cat(const Cat& right): Animal(right){
	std::cout << "Cat copy constructor" << std::endl;
	this->type = right.type;
	this->car_brain = new Brain(*right.car_brain);
}

Cat& Cat::operator=(const Cat& right){
	if (this != &right){
		this->type = right.type;
		delete this->car_brain;
		this->car_brain = new Brain(*right.car_brain);
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

Brain& Cat::getBrain() const{return (*this->car_brain);}