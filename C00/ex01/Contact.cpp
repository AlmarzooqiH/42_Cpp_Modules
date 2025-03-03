/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:41:52 by hamad             #+#    #+#             */
/*   Updated: 2025/03/03 23:27:49 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(){
}
Contact::Contact(std::string fName, std::string lName, std::string nickName, std::string pNumber, std::string darkestSecret){
    this->fName = fName;
    this->lName = lName;
    this->nickName = nickName;
    this->pNumber = pNumber;
    this->darkestSecret = darkestSecret;
}
std::string Contact::getFName(){
    return fName;
}
std::string Contact::getLName(){
    return lName;
}
std::string Contact::getNickName(){
    return nickName;
}
std::string Contact::getPNumber(){
    return pNumber;
}
std::string Contact::getDarkestSecret(){
    return darkestSecret;
}
void Contact::setFName(std::string fName){
    this->fName = fName;
}
void Contact::setLName(std::string lName){
    this->lName = lName;
}
void Contact::setNickName(std::string nickName){
    this->nickName = nickName;
}
void Contact::setPNumber(std::string pNumber){
    this->pNumber = pNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret){
    this->darkestSecret = darkestSecret;
}

void Contact::toString(){
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Nick Name: " << nickName << std::endl;
    std::cout << "Phone Number: " << pNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}