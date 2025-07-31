/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:49:53 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 19:49:53 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{

	protected:
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const std::string animalType);
		Animal(const Animal& right);
		Animal& operator=(const Animal& right);
		virtual void	makeSound() const;

		//Getters
		std::string getType() const;

		//Setters
		void setType(const std::string newType);
};
#endif