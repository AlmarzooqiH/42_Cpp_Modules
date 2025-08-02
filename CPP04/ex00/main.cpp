/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:18:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 17:18:27 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void){
	std::cout << "Improper Polymopirsm Test Started!" << std::endl << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl << "Animal Type: " << wrong_meta->getType() << std::endl;
	std::cout << "Animal Type: " << wrong_cat->getType() << std::endl;
	wrong_cat->makeSound();
	wrong_meta->makeSound();

	delete wrong_meta;
	delete wrong_cat;
	std::cout << std::endl << "Inproper Polymopirsm Completed!" << std::endl << std::endl;
	std::cout << "Proper Polymopirsm Test Started!" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	std::cout << std::endl << "Animal Type: " << dog->getType() << " " << std::endl;
	std::cout << "Animal Type: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	std::cout << std::endl << "Proper Polymopirsm Test Completed!" << std::endl << std::endl;
	delete meta;
	delete cat;
	delete dog;
	return (0);
}
