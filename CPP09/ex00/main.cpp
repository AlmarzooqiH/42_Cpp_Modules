/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:05:21 by hamalmar          #+#    #+#             */
/*   Updated: 2025/09/03 18:28:34 by hamalmar         ###   ########.fr       */
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
	return (0);
}
