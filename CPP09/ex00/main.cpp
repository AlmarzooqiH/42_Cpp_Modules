/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:05:21 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/30 11:17:08 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av){
	(void)ac;
	(void)av;
	std::map<int, std::string> m;

	m.insert(std::make_pair(2003, "Hamad"));
	std::cout << m[2003] << std::endl;
	std::cout << "Map max size: " << m.max_size() << std::endl;
	return (0);
}
