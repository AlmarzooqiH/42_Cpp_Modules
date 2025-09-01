/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:49:37 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/01 15:37:49 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const char *ElementNotFoundException::what() const throw(){
	return ("Element Not Found!");
}

int main(void){
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::vector<int> vec;
	int element = 0;
	for (int i = 0; i < 10; i++){
		int randomNum = (std::rand() % 100) + i;
		if (i == 5)
			element = randomNum;
		
		vec.push_back(randomNum);
	}

	std::cout << "Checking for existing element" << std::endl;

	try{
		easyfind(vec, element);
		std::cout << "Element(" << element <<") is inside the container" << std::endl;
	}catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}

	std::cout << std::endl << "Checking for a non existing element" << std::endl;

	try{
		easyfind(vec, 2003);
		std::cout << "Element(2003) is inside the container" << std::endl;
	}catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
