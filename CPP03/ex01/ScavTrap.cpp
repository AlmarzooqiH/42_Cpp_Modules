/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:57:19 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 19:57:13 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap default constructor" << std::endl;
	this->name = "ScavTrap";
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	this->maxHP = 100;
	this->maxEnergy = 50;
}

ScavTrap::ScavTrap(const ScavTrap& right): ClapTrap(right){
	std::cout << "ScavTrap copy constructor" << std::endl;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
	this->maxHP = 100;
	this->maxEnergy = 50;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap deconstructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name){
	std::cout << "ScavTrap name constructor" << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	this->maxHP = 100;
	this->maxEnergy = 50;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& right){
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &right){
		this->name = right.name;
		this->hp = right.hp;
		this->damage = right.damage;
		this->energy = right.energy;
		this->maxHP = right.maxHP;
		this->maxEnergy = right.maxEnergy;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target){
	if (this->hp <= 0){
	std::cout << "ScavTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	else if (this->energy <= 0){
		std::cout << "ScavTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;

}

void	ScavTrap::guardGate(){
	if (this->hp <= 0){
	std::cout << "ScavTrap " << this->name << " is dead." << std::endl;

		return ;
	}
	if (this->energy <= 0){
		std::cout << "ScavTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
