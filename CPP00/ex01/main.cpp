/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:03:23 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 14:19:20 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Utils.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	bool running = true;
	while (running)
	{
		std::string command, fName, lName, nName, pNumber, darkestSecret;
		std::cout << "Enter a command: (ADD (A), SEARCH (S), EXIT (E))" << std::endl;
		std::getline(std::cin, command);
		if (command.empty())
			continue;
		if (command == "EXIT" || command == "E")
		{
			running = false;
			continue;
		}
		else if (command == "ADD" || command == "A")
		{
			std::cout << "Enter first name: ";
			std::getline(std::cin, fName);
			std::cout << "Enter last name: ";
			std::getline(std::cin, lName);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nName);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, pNumber);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			if (validateContact(fName, lName, nName, pNumber, darkestSecret))
				continue;
			phoneBook.addContact(fName, lName, nName, pNumber, darkestSecret);
		}
		else if (command == "SEARCH" || command == "S")
		{
			phoneBook.displayContacts();
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}
