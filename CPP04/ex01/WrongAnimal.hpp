/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:24:15 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 20:07:57 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{

	protected:
		std::string type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const std::string animalType);
		WrongAnimal(const WrongAnimal& right);
		WrongAnimal& operator=(const WrongAnimal& right);
		void	makeSound() const;
		//Getters
		std::string getType() const;

		//Setters
		void setType(const std::string newType);
};

#endif