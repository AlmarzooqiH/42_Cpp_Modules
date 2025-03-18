/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:06:26 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 23:55:27 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon{
	private:
		std::string type;
	
	public:
		Weapon(std::string wType);
		~Weapon();
		const std::string	getType(void);
		void setType(std::string type);
};
#endif