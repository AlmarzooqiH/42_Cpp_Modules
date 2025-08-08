/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:39:26 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/08 12:03:38 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av){
	(void)ac;
	if (ac == 1){
		std::cerr << "Please provide an argument" << std::endl;
		return (2);
	}
	std::string str(av[1]);
	if (str.empty()){
		std::cerr << "Argument is empty" << std::endl;
		return (2);
	}
	try{
		ScalarConverter::convert(str);
	} catch (std::exception& err){
		std::cout << err.what() << std::endl;
	}
	return (0);
}
