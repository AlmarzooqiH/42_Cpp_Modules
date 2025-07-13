/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 00:23:03 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
/*#include "ClapTrap.hpp This is not needed since it is already being includ-
-ded insdid ScavTrap.hpp
*/

int	main(void){
	ClapTrap robinson("Gaylord Robinson");
	ScavTrap gumball("Gumball Watterson");
	ScavTrap darwin = gumball;
	robinson.takeDamage(1);
	gumball.beRepaired(10);
	gumball.takeDamage(2);
	gumball.guardGate();
	darwin.setName("Darwin Watterson");
	darwin.takeDamage(101);
	return (0);
}
