/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:59:10 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 15:20:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		static const int max_contacts = 8;
		int contact_count;
		int contact_pos;
		Contact contacts[8];
	public:
		PhoneBook();
		void addContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecert);
		void displayContacts();
		void formattedContact(std::string str);
};

#endif