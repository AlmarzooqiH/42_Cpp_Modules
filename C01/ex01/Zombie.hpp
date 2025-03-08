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
#include <iostream>
class Zombie{

	private:
		std::string name;
	
	public:
		Zombie();
		~Zombie();
		Zombie*		newZombie(std::string name);
		Zombie*		zombieHorde( int N, std::string name );
		void		randomChump(std::string name);
		void		announce(void);
		void		setName(std::string name);
		std::string	getName(void);
};