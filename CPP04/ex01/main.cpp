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
	const Cat* leo = new Cat();
	const Dog *bobby = new Dog();
	Brain& leo_brain = leo->getBrain();
	Brain& bobby_brain = bobby->getBrain();
	leo_brain.setIdea(0, "World Domination :3");
	leo_brain.setIdea(1, "Pet me Human");
	leo_brain.setIdea(2, "Give me treats");
	leo_brain.setIdea(3, "I will poop on the sofa");
	bobby_brain.setIdea(0, "Wow i love that guy!");
	bobby_brain.setIdea(1, "This human is my best freind");
	bobby_brain.setIdea(2, "Can i please have a treat?!");
	bobby_brain.setIdea(3, "Woof Woof :P");

	const Dog* larry = new Dog(*bobby);
	Brain& larry_brain = larry->getBrain();

	std::cout << "Before change" << std::endl;
	std::cout << "Bobby's idea at index 0: " << bobby_brain.getIdea(0) << std::endl;
	std::cout << "Larry's idea at index 0: " << larry_brain.getIdea(0) << std::endl;
	std::cout << "After change" << std::endl;
	larry_brain.setIdea(0, "I hate that guy!");
	std::cout << "Bobby's idea at index 0: " << bobby_brain.getIdea(0) << std::endl;
	std::cout << "Larry's idea at index 0: " << larry_brain.getIdea(0) << std::endl;

	const Cat* dosa = new Cat(*leo);
	Brain& dosa_brain = dosa->getBrain();

	std::cout << "Before change" << std::endl;
	std::cout << "Leo's idea at index 0: " << leo_brain.getIdea(0) << std::endl;
	std::cout << "Dosa's idea at index 0: " << dosa_brain.getIdea(0) << std::endl;
	std::cout << "After change" << std::endl;
	dosa_brain.setIdea(0, "I kinda hate that guy!");
	std::cout << "Leo's idea at index 0: " << leo_brain.getIdea(0) << std::endl;
	std::cout << "Dosa's idea at index 0: " << dosa_brain.getIdea(0) << std::endl;
	
	delete leo;
	delete bobby;
	delete larry;
	delete dosa;
	return (0);
}
