/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:42:50 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/14 00:11:17 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap defualt constructor" << std::endl;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap deconstructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name){
	std::cout << "ClapTrap name constructor" << std::endl;
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& right){
	this->name = right.name;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& right){
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &right){
	this->name = right.name;
	this->hp = right.hp;
	this->damage = right.damage;
	this->energy = right.energy;
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
	std::cout << "ClapTrap " << this->name << "attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hp <= 0){
	std::cout << "ClapTrap " << this->name << " is dead." << std::endl;
	return ;
	}
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << "has taken " << amount << " of damange, " << "HP now is: " << this->hp << std::endl;
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
	this->hp += amount;
	this->energy--;
	std::cout << "ClapTrap " << this->name << "has reparied " << amount << " of HP" << std::endl;
}

std::string	ClapTrap::getName() const{
	return (this->name);
}

int	ClapTrap::getHP() const{
	return (this->hp);
}

int	ClapTrap::getEnergy() const{
	return (this->energy);
}

int	ClapTrap::getDamage() const{
	return (this->damage);
}

void	ClapTrap::setName(const std::string newName){
	this->name = newName;
}

void	ClapTrap::setHP(int newHp){
	this->hp = newHp;
}

void	ClapTrap::setEnergy(int newEnergy){
	this->energy = newEnergy;
}

void	ClapTrap::setDamage(int newDamage){
	this->damage = newDamage;
}