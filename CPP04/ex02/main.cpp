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
	std::cout << "Abstraction Test Started!!!" << std::endl << std::endl;
	const Animal* leo = new Cat();
	const Animal* bobby = new Dog();

	std::cout << std::endl << "Leo is a " << leo->getType() << std::endl;
	std::cout << "Bobby is a " << bobby->getType() << std::endl << std::endl;
	std::cout << "Abstraction Test Completed!!!" << std::endl << std::endl;
	delete leo;
	delete bobby;
	return 0;
}