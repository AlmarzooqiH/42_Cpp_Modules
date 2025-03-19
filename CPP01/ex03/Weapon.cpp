/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:11:52 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 23:55:59 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string wType): type(wType){}

Weapon::~Weapon(){
	std::cout << this->type << " has been broken into pieces" << std::endl;
}

const std::string	Weapon::getType(void){
	return this->type;
}

void Weapon::setType(std::string wName){
	this->type = wName;
}