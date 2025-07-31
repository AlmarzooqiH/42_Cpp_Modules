/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 19:51:58 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
/*#include "ClapTrap.hpp This is not needed since it is already being includ-
-ded insdid ScavTrap.hpp
*/

int	main(void){
	ClapTrap mansour("Mansour");
	ScavTrap rashid("Rashid");
	FragTrap hamad("Hamad");

	std::cout << "====== ClapTrap Test Started! ======" << std::endl;
	mansour.takeDamage(1232123);
	mansour.beRepaired(123);
	mansour.attack("Rashid");
	std::cout << "====== ClapTrap Test Completed! ======" << std::endl;
	std::cout<< std::endl;
	std::cout << "ScavTrap Test Started" << std::endl;
	rashid.beRepaired(12345432);
	for (int i = 0; i < 12; i++){
		rashid.takeDamage(1);
	}
	rashid.guardGate();
	std::cout << "====== ScavTrap Test Completed! ======" << std::endl;
	std::cout<< std::endl;
	std::cout << "FragTrap Test Started" << std::endl;
	hamad.attack("Mansour");
	hamad.attack("Rashid");
	hamad.takeDamage(10);
	hamad.beRepaired(2);
	hamad.highFivesGuys();
	std::cout << "====== FragTrap Test Completed! ======" << std::endl;
	return (0);
}
