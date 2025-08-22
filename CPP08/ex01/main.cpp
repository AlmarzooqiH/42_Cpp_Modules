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
	const size_t spanSizeOptions[] = {100, 1000, 234978, 10293, 2345927, 25000};
	size_t spanSize = spanSizeOptions[std::rand() % 6];
	Span sp = Span(spanSize);
	for (size_t i = 0; i < spanSize; i++){
		int randNumber = std::rand() % 20031008;
		try{
		sp.addNumber(randNumber);
		} catch (std::exception& err){
			std::cerr << err.what() << std::endl;
		}
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
