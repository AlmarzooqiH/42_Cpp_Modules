/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:41:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/15 10:54:42 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "WrongCat defualt constructor" << std::endl;
}

WrongCat::WrongCat(const std::string animalType): WrongAnimal(animalType){
	std::cout << "WrongCat type constructor" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat deconstructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& right): WrongAnimal(right){
	std::cout << "WrongCat copy constructor" << std::endl;
	this->type = right.type;
}

WrongCat& WrongCat::operator=(const WrongCat& right){
	if (this != &right){
		this->type = right.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}
