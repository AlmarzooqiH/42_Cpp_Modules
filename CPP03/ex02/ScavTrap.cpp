/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:57:19 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 15:30:12 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap default constructor" << std::endl;
	this->name = "ScavTrap";
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& right): ClapTrap(right){
	std::cout << "ScavTrap copy constructor" << std::endl;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap deconstructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name){
	std::cout << "ScavTrap name constructor" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& right){
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &right){
		this->name = right.name;
		this->hp = right.hp;
		this->damage = right.damage;
		this->energy = right.energy;
	}
	return (*this);
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}