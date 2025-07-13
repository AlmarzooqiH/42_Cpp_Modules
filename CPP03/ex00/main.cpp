/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:40 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 00:16:48 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void){
	ClapTrap clarp;
	ClapTrap trap("Gaylord Robinson");
	clarp.attack("Bob");
	trap.takeDamage(1111);
	trap.takeDamage(1);
	trap.attack("Meowzer");
	clarp.beRepaired(1111111111);
	clarp.takeDamage(1111111121);
	clarp.beRepaired(10);
	return (0);
}