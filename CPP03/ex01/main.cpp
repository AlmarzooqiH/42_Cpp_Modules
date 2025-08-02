/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/02 14:05:59 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void){
	ClapTrap mansour("Mansour");
	ScavTrap rashid("Rashid");

	std::cout << "====== ClapTrap Test Started! ======" << std::endl;
	mansour.takeDamage(1232123);
	mansour.beRepaired(123);
	mansour.attack("Rashid");
	std::cout << "====== ClapTrap Test Completed! ======" << std::endl;
	std::cout<< std::endl;
	std::cout << "ScavTrap Test Started" << std::endl;
	rashid.beRepaired(12345432);
	rashid.guardGate();
	for (int i = 0; i < 12; i++){
		rashid.takeDamage(1);
	}
	rashid.guardGate();
	std::cout << "====== ScavTrap Test Completed! ======" << std::endl;
	return (0);
}
