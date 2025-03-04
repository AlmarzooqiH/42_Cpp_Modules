/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:59:39 by hamad             #+#    #+#             */
/*   Updated: 2025/03/04 10:32:34 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(){
    contact_count = 0;
    contact_pos = 0;
}

void PhoneBook::addContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecert){
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
		std::cout << str.substr(0, 9) << ".";
		return ;
	}
	for (int i = 0; i < 10 - str.length(); i++)
		std::cout << " ";
	std::cout << str << "|";
}

void    PhoneBook::displayContacts()
{
	if (contact_count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
    int	contact_index = 0;
	std::cout << "        ID|     fName|     lName|  NickName|" << std::endl;
    for (Contact contact: contacts)
    {
		if (contact_index == contact_count)
			break;
		formattedContact(std::to_string(contact_index + 1));
		formattedContact(contact.getFName());
		formattedContact(contact.getLName());
		formattedContact(contact.getNickName());
		std::cout << std::endl;
        contact_index++;
    }
	contact_index = -1;
	do
	{
		std::cout << "Enter the ID of the contact you want to view: " << std::endl;
		std::cin >> contact_index;
	}while (contact_index < 1 || contact_index > contact_count);
	contact_index--;
	this->contacts[contact_index].toString();
}
