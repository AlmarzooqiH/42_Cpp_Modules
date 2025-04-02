/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:59:39 by hamad             #+#    #+#             */
/*   Updated: 2025/04/02 15:55:26 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Utils.hpp"

PhoneBook::PhoneBook(){
	contact_count = 0;
	contact_pos = 0;
}

void	PhoneBook::addContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecert){
	if (contact_count == max_contacts)
	{
		int pos = contact_pos % max_contacts;
		contacts[pos].setFName(fName);
		contacts[pos].setLName(lName);
		contacts[pos].setNickName(nName);
		contacts[pos].setPNumber(pNumber);
		contacts[pos].setDarkestSecret(darkestSecert);
		contact_pos++;
		return ;
	}
	contacts[contact_pos] = Contact(fName, lName, nName, pNumber, darkestSecert); 
	contact_pos++;
	contact_count++;
}

void	PhoneBook::formattedContact(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".|";
		return ;
	}
	for (int i = 0; i < 10 - str.length(); i++)
		std::cout << " ";
	std::cout << str << "|";
}

void	PhoneBook::displayContacts()
{
	if (contact_count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	int	contact_index = 0;
	std::cout << "        ID|     fName|     lName|  NickName|" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		if (contact_index == contact_count)
			break;
		formattedContact(std::to_string(contact_index + 1));
		formattedContact(contacts[i].getFName());
		formattedContact(contacts[i].getLName());
		formattedContact(contacts[i].getNickName());
		std::cout << std::endl;
		contact_index++;
	}
	contact_index = -1;
	do
	{	
		std::cout << "Enter the ID of the contact you want to view: " << std::endl;
		std::cin >> contact_index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}while (contact_index < 1 || contact_index > contact_count);
	this->contacts[contact_index - 1].toString();
}
