/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 19:31:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
/*#include "ClapTrap.hpp This is not needed since it is already being includ-
-ded insdid ScavTrap.hpp
*/

int	main(void){
	ClapTrap garry("Garry");
	ScavTrap bob("Bob");
	ScavTrap darwin = bob;
	garry.takeDamage(1);
	bob.beRepaired(10);
	bob.takeDamage(2);
	bob.guardGate();
	darwin.takeDamage(101);
	return (0);
}
