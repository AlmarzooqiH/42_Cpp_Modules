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

int main(void){
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
	// sp.printSpan();
	try{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
