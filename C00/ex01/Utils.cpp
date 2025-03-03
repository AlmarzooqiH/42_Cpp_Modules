/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:28:33 by hamad             #+#    #+#             */
/*   Updated: 2025/03/03 22:35:39 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Utils.hpp"

bool validateContact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string darkestSecret){
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
    return false;
}

