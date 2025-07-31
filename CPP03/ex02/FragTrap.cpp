/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:45:10 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 16:45:10 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "FragTrap defualt constructor" << std::endl;
	this->name = "FragTrap";
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap deconstructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap name constructor" << std::endl;
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& right): ClapTrap(right){
	std::cout << "FragTrap copy constructor" << std::endl;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
}

FragTrap& FragTrap::operator=(const FragTrap& right){
	std::cout << "FragTrap operator = constructor" << std::endl;
	if (this != &right){
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap requesting a highfive! ✋✋✋✋" << std::endl;
}
