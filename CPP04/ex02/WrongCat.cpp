/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:41:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/02 19:07:11 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "WrongCat Defualt Constructor" << std::endl;
}

WrongCat::WrongCat(const std::string animalType): WrongAnimal(animalType){
	std::cout << "WrongCat Type Constructor" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Deconstructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& right): WrongAnimal(right){
	std::cout << "WrongCat Copy Constructor" << std::endl;
	this->type = right.type;
}

WrongCat& WrongCat::operator=(const WrongCat& right){
	std::cout << "WrongCat Copy Assignment Constructor" << std::endl;
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const{
	std::cout << this->type << ": Meow Meow" << std::endl;
}
