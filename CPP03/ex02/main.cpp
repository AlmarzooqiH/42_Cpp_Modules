/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 17:09:17 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
/*#include "ClapTrap.hpp This is not needed since it is already being includ-
-ded insdid ScavTrap.hpp
*/

int	main(void){
	ClapTrap robinson("Gaylord Robinson");
	ScavTrap gumball("Gumball Watterson");
	ScavTrap darwin = gumball;
	FragTrap richard("Richard Watterson");
	ClapTrap anais;

	robinson.takeDamage(1);
	gumball.beRepaired(10);
	richard.attack("Gumball");
	richard.attack("Darwin");
	gumball.takeDamage(2);
	gumball.guardGate();
	darwin.setName("Darwin Watterson");
	darwin.takeDamage(101);
	while (richard.getEnergy() > 0){
		richard.attack("Richard's Shadow");
	}
	richard.attack("Richard's Shadow");
	richard.beRepaired(10);
	richard.attack("Richard's Shadow");
	anais.attack("Darwin"); // To check if the ClapTrap will display a name or not.
	return (0);
}
