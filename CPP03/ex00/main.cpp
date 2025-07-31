/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 19:52:51 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void){
	ClapTrap mansour("Mansour");

	std::cout << "====== ClapTrap Test Started! ======" << std::endl;
	mansour.takeDamage(1232123);
	mansour.beRepaired(123);
	mansour.attack("Rashid");
	std::cout << "====== ClapTrap Test Completed! ======" << std::endl;
	std::cout<< std::endl;;
	return (0);
}