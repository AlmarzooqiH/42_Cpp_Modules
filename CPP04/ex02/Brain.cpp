/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:12:24 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/15 14:38:53 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain defualt constructor" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain deconstructor" << std::endl;
}

Brain::Brain(const Brain& right){
	std::cout << "Brain copy constructor" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = right.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& right){
	if (this != &right){
		for (int i = 0; i < 100; i++){
			this->ideas[i] = right.ideas[i];
		}
	}	
	return (*this);
}

std::string Brain::getIdea(size_t index) const{
	if (index >= 100)
		return ("");
	return (ideas[index]);
}

void Brain::setIdea(size_t index, const std::string newIdea){
	if (index >= 100)
		return ;
	ideas[index] = newIdea;
}

