/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:03:23 by hamad             #+#    #+#             */
/*   Updated: 2025/03/03 23:36:24 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Utils.hpp"

int main(void)
{
    PhoneBook phoneBook;
    bool running = true;
    while (running)
    {
        std::string command, fName, lName, nName, pNumber, darkestSecret;
        std::cout << "Enter a command: (ADD (A), SEARCH (S), EXIT (E))" << std::endl;
        std::cin >> command;
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
            std::cin >> fName;
            std::cout << "Enter last name: ";
            std::cin >> lName;
            std::cout << "Enter nickname: ";
            std::cin >> nName;
            std::cout << "Enter phone number: ";
            std::cin >> pNumber;
            std::cout << "Enter darkest secret: ";
            std::cin >> darkestSecret;
            if (validateContact(fName, lName, nName, pNumber, darkestSecret))
                continue;
            phoneBook.addContact(fName, lName, nName, pNumber, darkestSecret);
        }
        else if (command == "SEARCH" || command == "S")
        {
            phoneBook.displayContacts();
        }
    }
    return (0);
}
