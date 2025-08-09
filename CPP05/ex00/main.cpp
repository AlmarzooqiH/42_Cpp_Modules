/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:15:01 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 19:15:01 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat jeff("jeff", 1);
	Bureaucrat larry("larry", 150);

	std::cout << "===========================================" << std::endl;
	std::cout << "Bureaucrats: " << std::endl;
	std::cout << jeff << std::endl;
	std::cout << larry << std::endl;

	std::cout << "===========================================" << std::endl;

	std::cout << jeff.getName() << " will try to increment his grade" << std::endl;
	try {
		jeff.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jeff << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << larry.getName() << " will try to decrement his grade" << std::endl;
	try {
		larry.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << larry << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << jeff.getName() << " will try to decrement his grade" << std::endl;
	try {
		jeff.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << jeff << std::endl;
	std::cout << "===========================================" << std::endl;

	std::cout << larry.getName() << " will try to increment his grade" << std::endl;
	try {
		larry.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << larry << std::endl;
	std::cout << "===========================================" << std::endl;

	return (0);
}
