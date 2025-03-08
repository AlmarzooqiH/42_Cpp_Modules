/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:46:32 by hamad             #+#    #+#             */
/*   Updated: 2025/03/08 14:49:11 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombies = zombieHorde(3, "Zombie");
	for (int i = 0; i < 3; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}
