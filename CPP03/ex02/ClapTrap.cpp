/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:42:50 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/31 19:45:25 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->name = "ClapTrap";
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	this->maxHP = 10;
	this->maxEnergy = 10;
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name){
	std::cout << "ClapTrap name consturctor" << std::endl;
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	this->maxHP = 10;
	this->maxEnergy = 10;
}

ClapTrap::ClapTrap(const ClapTrap& right){
	this->name = right.name;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
	this->maxHP = right.maxHP;
	this->maxEnergy = right.maxEnergy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& right){
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

void	ClapTrap::attack(const std::string& target){
	if (this->hp <= 0){
	std::cout << "ClapTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	else if (this->energy <= 0){
		std::cout << "ClapTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hp <= 0){
	std::cout << "ClapTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	this->hp = ((this->hp - amount) <= 0) ? 0 : this->hp - amount;
	if (this->hp <= 0)
		this->hp = 0;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " of damange, " << "HP now is: " << this->hp << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->hp <= 0){
	std::cout << "ClapTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	else if (this->energy <= 0){
		std::cout << "ClapTrap " << this->name << " has run of energy" << std::endl;
		return ;
	}
	this->hp = ((this->hp + amount) > this->maxHP) ? 10 : this->hp + amount;
	this->energy--;
	std::cout << "ClapTrap " << this->name << " has reparied " << amount << " of HP" << std::endl;
}
