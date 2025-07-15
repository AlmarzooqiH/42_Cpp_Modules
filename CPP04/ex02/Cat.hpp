/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:03:30 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 21:03:30 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal{
	private:
		Brain *car_brain;

	public:
		Cat();
		~Cat();
		Cat(const std::string animalType);
		Cat(const Cat& right);
		Cat& operator=(const Cat& right);
		void	makeSound() const;
		Brain&	getBrain() const;
};
#endif
