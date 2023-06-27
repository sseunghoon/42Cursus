/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/23 17:24:53 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	name = "default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap constructor called: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap constructor called: " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& fixed) {
	std::cout << "ClapTrap Copy constructor called: " << name << std::endl;
	*this = fixed;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& fixed) {
	std::cout << "ClapTrap Copy assignment operator called: " << name << std::endl;
	name = fixed.name;
	hitPoints = fixed.hitPoints;
	energyPoints = fixed.energyPoints;
	attackDamage = fixed.attackDamage;
	
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "[ERROR] ClapTrap(" << name << ") can't attack " << target;
		if (this->hitPoints == 0) {
			std::cout << ", " << name << " is dead!" << std::endl;
		} else {
			std::cout << ", " << name << " has no energy!" << std::endl;
		}
		return ;
	}
	energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attaks " << 
	target << ", causing " << attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "[ERROR] ClapTrap(" << name << ") can't take Damage, "
		<< name << " is Already dead" << std::endl;
		return ;
	}
	if (hitPoints < amount) {
		hitPoints = 0;
	} else {
		hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->name << " take " << 
	amount << " points of damage, Current HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "[ERROR] ClapTrap(" << name << ") can't repair itself, ";
		if (this->hitPoints == 0) {
			std::cout << ", " << name << " is dead!" << std::endl;
		} else {
			std::cout << ", " << name << " has no energy!" << std::endl;
		}
		return ;
	}
	energyPoints -= 1;
	hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repaired itself as much as " << 
	amount << " points, Current HP: " << hitPoints << std::endl;
}
