/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:25:35 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/21 15:25:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av){
	try {
		PmergeMe yes(ac, av);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
