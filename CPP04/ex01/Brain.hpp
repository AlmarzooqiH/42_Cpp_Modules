/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:29 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/15 11:46:30 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain{
	private:
		std::string	ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& right);
		Brain& operator=(const Brain& right);
		std::string	getIdea(size_t index) const;
		void	setIdea(size_t index, const std::string newIdea);
};
#endif