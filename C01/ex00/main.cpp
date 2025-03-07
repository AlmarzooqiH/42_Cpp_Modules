/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:11:54 by hamalmar          #+#    #+#             */
/*   Updated: 2025/03/06 18:11:54 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
Zombie*	newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    Zombie *zombie = newZombie("Zombie1");
    zombie->announce();
    randomChump("Zombie2");
    delete zombie;
    return (0);
}
