/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:41:49 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 16:41:49 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& right);
	FragTrap& operator =(const  FragTrap& right);
	void	highFivesGuys(void);
	~FragTrap();
};
#endif