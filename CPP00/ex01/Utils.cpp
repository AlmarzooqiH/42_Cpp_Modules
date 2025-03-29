/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:28:33 by hamad             #+#    #+#             */
/*   Updated: 2025/03/29 15:21:58 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	validateContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecret){
	bool empty = false;
	if (fName.empty())
	{
		std::cout << "First name cannot be empty" << std::endl;
		empty = true;
	}
	if (lName.empty())
	{
		std::cout << "Last name cannot be empty" << std::endl;
		empty = true;
	}
	if (nName.empty())
	{
		std::cout << "Nickname cannot be empty" << std::endl;
		empty = true;
	}
	if (pNumber.empty())
	{
		std::cout << "Phone number cannot be empty" << std::endl;
		empty = true;
	}
	if (darkestSecret.empty())
	{
		std::cout << "Darkest secret cannot be empty" << std::endl;
		empty = true;
	}
	if (empty)
		return true;
	for (int i = 0; i < pNumber.length(); i++)
	{
		if (!ft_isdigit(pNumber[i]))
		{
			std::cout << "Phone number must contain only digits" << std::endl;
			return true;
		}
	}
	return false;
}

