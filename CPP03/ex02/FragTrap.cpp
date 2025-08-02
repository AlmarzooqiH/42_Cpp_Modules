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
	std::cout << "FragTrap Defualt Constructor" << std::endl;
	this->name = "FragTrap";
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	this->maxHP = 100;
	this->maxEnergy = 100;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Deconstructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap Name Constructor" << std::endl;
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	this->maxHP = 100;
	this->maxEnergy = 100;
}

FragTrap::FragTrap(const FragTrap& right): ClapTrap(right){
	std::cout << "FragTrap Copy Constructor" << std::endl;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
	this->maxHP = right.maxHP;
	this->maxEnergy = right.maxEnergy;
}

FragTrap& FragTrap::operator=(const FragTrap& right){
	std::cout << "FragTrap Copy Assignment Constructor" << std::endl;
	if (this != &right){
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
	this->maxHP = right.maxHP;
	this->maxEnergy = right.maxEnergy;
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target){
	if (this->hp <= 0){
	std::cout << "FragTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	else if (this->energy <= 0){
		std::cout << "FragTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;

}

void	FragTrap::highFivesGuys(void){
	if (this->hp <= 0){
		std::cout << "FragTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	else if (this->energy <= 0){
		std::cout << "FragTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap requesting a highfive! ✋✋✋✋" << std::endl;
}
