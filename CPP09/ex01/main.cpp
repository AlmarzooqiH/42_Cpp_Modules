/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:10:55 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/14 11:10:55 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cerr << "Input must be ./RPN [\"expression\"]" << std::endl;
		return (2);
	}
	try{
		std::string tmp(av[1]);
		RPN rpn(tmp);

	}catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
