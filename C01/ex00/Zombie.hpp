/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:12:16 by hamalmar          #+#    #+#             */
/*   Updated: 2025/03/06 18:12:16 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
class Zombie{

	private:
		std::string name;
	
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void		announce(void);
		void		setName(std::string name);
		std::string	getName(void);
};
	Zombie*		newZombie(std::string name);
	void		randomChump(std::string name);

#endif