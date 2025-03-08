/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:06:26 by hamad             #+#    #+#             */
/*   Updated: 2025/03/08 15:11:33 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon{
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(std::string wName);
		const std::string	getType(void);
		void setType(std::string type);
};
#endif