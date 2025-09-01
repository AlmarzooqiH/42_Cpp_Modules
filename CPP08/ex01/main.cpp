/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:21:14 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/22 09:21:14 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

//My main
int main(void){
	std::cout << "Adding values normally" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	const size_t spanSizeOptions[] = {1, 10, 100, 1000, 10000, 15000, 20000, 25000};
	size_t spanSize = spanSizeOptions[std::rand() % 8];
	Span sp = Span(spanSize);
	for (size_t i = 0; i < spanSize; i++){
		int randNumber = std::rand() % 300;
		try{
		sp.addNumber(randNumber);
		} catch (std::exception& err){
			std::cerr << err.what() << std::endl;
		}
	}
	try{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	sp.printSpan();
	std::cout << std::endl << "Adding numbers via range operators" << std::endl;
	Span sp2(spanSize);

	try{
		sp2.addNumber(sp.begin(), sp.end());
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	std::cout << "Min and Max of sp2: " << std::endl;
	try{
		std::cout << "Min: " << sp2.shortestSpan() << std::endl;
		std::cout << "Max: " << sp2.longestSpan() << std::endl;
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	sp2.printSpan();
	return (0);
}


//Subject file Main:
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return (0);
// }
