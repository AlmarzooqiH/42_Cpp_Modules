/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:12:08 by hamalmar          #+#    #+#             */
/*   Updated: 2025/03/06 18:12:08 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){
        std::cout << name << ":\tOmae Wa Mou Shindeiru\nNANIIIIIII?!?!?!?" << std::endl;
}
Zombie::Zombie(std::string name){this->name = name;}
void    Zombie::announce(void){
        std::cout << name << ":\tBraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
        this->name = name;
}

std::string     Zombie::getName(void){
        return (name);
}