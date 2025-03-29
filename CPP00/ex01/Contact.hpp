/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:59:22 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 14:18:05 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact {
	private:
		std::string fName;
		std::string lName;
		std::string nickName;
		std::string pNumber;
		std::string darkestSecret;
	public:
		Contact();
		Contact(std::string fName, std::string lName, std::string nickName, std::string pNumber, std::string darkestSecret);
		std::string getFName();
		std::string getLName();
		std::string getNickName();
		std::string getPNumber();
		std::string getDarkestSecret();
		void setFName(std::string fName);
		void setLName(std::string lName);
		void setNickName(std::string nickName);
		void setPNumber(std::string pNumber);
		void setDarkestSecret(std::string darkestSecret);
		void toString();
};

#endif