/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:05:21 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/08 17:45:27 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av){
	if (ac != 2){
		std::cerr << "Argument must be ./btc [data file]" << std::endl;
		return (2);
	}
	try{
		std::string tmp(av[1]);
		BitcoinExchange test(tmp);
	} catch (std::exception& err){
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
