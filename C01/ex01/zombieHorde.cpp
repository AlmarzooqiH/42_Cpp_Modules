/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:48:02 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 22:43:51 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* dead_people = new Zombie[N];
	for (int i = 0 ; i < N; i++)
	{
		dead_people[i].setName(name);
	}
	return dead_people;
}