/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:18:04 by hamad             #+#    #+#             */
/*   Updated: 2025/03/19 00:04:25 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){this->name = name;}

void HumanB::setWeapon(Weapon &weapon){this->weapon = &weapon;}

HumanB::~HumanB()
{
    std::cout << this->name << " has been killed" << std::endl;
}

void    HumanB::attack(void)
{
    if (this->weapon != NULL)
    {
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
        return ;
    }
    std::cout << this->name << " attacks with their fist"<< std::endl;
}
