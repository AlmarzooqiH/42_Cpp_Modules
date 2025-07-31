/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 14:42:41 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
/*#include "ClapTrap.hpp This is not needed since it is already being includ-
-ded insdid ScavTrap.hpp
*/

int	main(void){
	ClapTrap garry("Garry");
	ScavTrap bob("Bob");
	ScavTrap darwin = bob;
	FragTrap hamad("Hamad");
	ClapTrap jeff;

	garry.takeDamage(1);
	bob.beRepaired(10);
	hamad.attack("Bob");
	hamad.attack("Bob");
	bob.takeDamage(2);
	bob.guardGate();
	darwin.setName("Darwin");
	darwin.takeDamage(101);
	while (hamad.getEnergy() > 0){
		hamad.attack("Hamad's Shadow");
	}
	hamad.attack("Hamad's Shadow");
	hamad.beRepaired(10);
	hamad.attack("Hamad's Shadow");
	jeff.attack("Darwin"); // To check if the ClapTrap will display a name or not.
	return (0);
}
