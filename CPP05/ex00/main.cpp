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

	try {
		jeff.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << jeff.getName() << " is already at the highest grade: "
		          << jeff.getGrade() << std::endl;
		std::cout << "TLDR: " << e.what() << std::endl;
	}
	std::cout << "===========================================" << std::endl;
	try {
		larry.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "At this point just fire " << larry.getName()
		          << ", his grade is: " << larry.getGrade() << std::endl;
		std::cout << "TLDR: " << e.what() << std::endl;
	}
	return (0);
}
