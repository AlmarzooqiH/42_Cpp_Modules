/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:59:39 by hamad             #+#    #+#             */
/*   Updated: 2025/03/03 23:29:33 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
		std::cout << "        " << contact_index + 1 << "|";
		if (contact.getFName().length() > 10)
			std::cout << contact.getFName().substr(0, 9) << ".|";
		else
			std::cout << contact.getFName() << "|";
		if (contact.getLName().length() > 10)
			std::cout << contact.getLName().substr(0, 9) << ".|";
		else
			std::cout << contact.getLName() << "|";
		if (contact.getNickName().length() > 10)
			std::cout << contact.getNickName().substr(0, 9) << ".|";
		else
			std::cout << contact.getNickName() << "|";
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
