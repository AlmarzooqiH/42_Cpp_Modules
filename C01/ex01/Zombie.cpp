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

#include <iostream>
#include "Zombie.hpp"

void    Zombie::announce(void){
        std::cout << name << ":\tBraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
        this->name = name;
}

std::string     Zombie::getName(void){
        return (name);
}