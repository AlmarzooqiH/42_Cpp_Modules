/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:36:55 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 20:36:55 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{
	private:
		Brain* dog_brain;

	public:
		Dog();
		~Dog();
		Dog(const std::string animalType);
		Dog(const Dog& right);
		Dog& operator=(const Dog& right);
		void	makeSound() const;
		Brain& getBrain() const;
};
#endif
