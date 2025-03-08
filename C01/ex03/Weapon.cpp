/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:11:52 by hamad             #+#    #+#             */
/*   Updated: 2025/03/08 15:12:53 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string wName){
	type = wName;
}

const std::string	Weapon::getType(void){
	return (const std::string)type;
}

void Weapon::setType(std::string wName){
	type = wName;
}