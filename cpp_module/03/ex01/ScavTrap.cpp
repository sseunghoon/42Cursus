/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/07/04 01:38:29 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called: " << name << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called: " << name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& fixed) {
	std::cout << "ScavTrap Copy constructor called: " << name << std::endl;
	*this = fixed;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& fixed) {
	std::cout << "ScavTrap Copy assignment operator called: " << name << std::endl;
	name = fixed.name;
	hitPoints = fixed.hitPoints;
	energyPoints = fixed.energyPoints;
	attackDamage = fixed.attackDamage;
	
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "[ERROR] ScavTrap(" << name << ") can't attack " << target;
		if (this->hitPoints == 0) {
			std::cout << ", " << name << " is dead!" << std::endl;
		} else {
			std::cout << ", " << name << " has no energy!" << std::endl;
		}
		return ;
	}
	energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attaks " << 
	target << ", causing " << attackDamage << " points of damage" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->energyPoints != 0) {
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
	} else {
		std::cout << "ScavTrap " << this->name << " has no energy." << std::endl;
	}
}
