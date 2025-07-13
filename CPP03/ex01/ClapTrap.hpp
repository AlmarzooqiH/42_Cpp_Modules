/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:58:58 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/13 15:55:39 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap{

	private:
	std::string	name;
	int			hp;
	int			energy;
	int			damage;

	public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& right);
	ClapTrap& operator=(const ClapTrap& right);
	~ClapTrap();
	
	/*			Methods			 */
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
#endif