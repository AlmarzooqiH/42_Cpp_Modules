/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:18:27 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/02 15:50:00 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void){
	std::string catIdeas[] = {"PET ME SERVANT", "Give me a treat or the tv will go sky diving", "World Domination!", "I will bite you!", "I shall poop everywhere :3"};
	std::string dogIdeas[] = {"Wow i love that guy :D", "What a legend", "We Are BFF", "Lets go for a Walk", "Woof Woof!!!!!"};
	const int catIdeasSize = 5;
	const int dogIdeasSize = 5;
	const int size = 4;
	Animal *zoo[size];

	std::cout << "Animal Selfawareness Test Started!" << std::endl << std::endl;

	for (int i = 0; i < size; i++){
		if (i < (size / 2)){
			zoo[i] = new Cat("Larry El Gato");
		} else {
			zoo[i] = new Dog("Bobby");
		}
	}

	for (int i = 0; i < size; i++){
		std::srand(std::time(NULL) + i + (size / 2));
		if (i < (size / 2)){
			Cat *larry = (Cat *)zoo[i];
			Brain &larryBrain = larry->getBrain();
			for (int k = 0; k < catIdeasSize; k++){
				int randIndex = std::rand() % catIdeasSize;
				larryBrain.setIdea(k, catIdeas[randIndex]);
			}
		} else {
			Dog *bobby = (Dog *)zoo[i];
			Brain &bobbyBrain = bobby->getBrain();
			for (int k = 0; k < dogIdeasSize; k++){
				int randIndex = std::rand() % dogIdeasSize;
				bobbyBrain.setIdea(k, dogIdeas[randIndex]);
			}
		}
	}

	std::cout << std::endl << "Animals Thoughts" << std::endl;
	for (int i = 0; i < size; i++){
		if (i < (size / 2)){
			std::cout << "Cat[" << i << "] is Thinking of: " << std::endl;
			Cat *larry = (Cat *)zoo[i];
			Brain &larryBrain = larry->getBrain();
			for (int k = 0; k < catIdeasSize; k++){
				std::cout << "Idea[" << k << "]: " << larryBrain.getIdea(k) << std::endl;
			}
			std::cout << std::endl;
		} else {
			std::cout << "Dog[" << i << "] is Thinking of: " << std::endl;
			Dog *bobby = (Dog *)zoo[i];
			Brain &bobbyBrain = bobby->getBrain();
			for (int k = 0; k < dogIdeasSize; k++){
				std::cout << "Idea[" << k << "]: " << bobbyBrain.getIdea(k) << std::endl;
			}
			std::cout << std::endl;
		}
	}

	Cat	*leo = new Cat(*(Cat *)zoo[0]);
	std::cout << std::endl << "Copied Cat: " << (Cat *)zoo[0] << std::endl; 
	std::cout << "Leo: "<< leo << std::endl << std::endl << "Leo's Thoughts:" << std::endl;
	Brain &leoBrain = leo->getBrain();
	for (int i = 0; i < catIdeasSize; i++){
		std::cout << "Idea[" << i << "]: " << leoBrain.getIdea(i) << std::endl;
	}
	std::cout << std::endl << "Leo has Died" << std::endl;
	delete leo;
	std::cout << std::endl << "The Death Of Larries And Bobbies" << std::endl << std::endl;
	for (int i = 0; i < size; i++){
		if (i < (size / 2))
			std::cout << "Cat[" << i << "]: Has Died" << std::endl;
		else
			std::cout << "Dog[" << i << "]: Has Died" << std::endl;
		delete zoo[i];
		std::cout << std::endl;
	}
	return (0);
}
