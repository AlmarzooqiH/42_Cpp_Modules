/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:02:56 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 23:58:16 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), hWeapon(weapon){}

HumanA::~HumanA()
{
    std::cout << this->name << " has been killed" << std::endl;
}

void    HumanA::attack(void){
    std::cout << this->name << " attacks with their " << hWeapon.getType() << std::endl;
}