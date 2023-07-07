/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/23 20:09:46 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called: " << name << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called: " << name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& fixed) : ClapTrap(fixed.name) {
	std::cout << "FragTrap Copy constructor called: " << name << std::endl;
	*this = fixed;
}

FragTrap& FragTrap::operator=(const FragTrap& fixed) {
	std::cout << "FragTrap Copy assignment operator called: " << name << std::endl;
	name = fixed.name;
	hitPoints = fixed.hitPoints;
	energyPoints = fixed.energyPoints;
	attackDamage = fixed.attackDamage;
	
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "[ERROR] FragTrap(" << name << ") can't attack " << target;
		if (this->hitPoints == 0) {
			std::cout << ", " << name << " is dead!" << std::endl;
		} else {
			std::cout << ", " << name << " has no energy!" << std::endl;
		}
		return ;
	}
	energyPoints -= 1;
	std::cout << "FragTrap " << this->name << " attaks " << 
	target << ", causing " << attackDamage << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "[ERROR] FragTrap(" << name << ") can't highFive, ";
		if (this->hitPoints == 0) {
			std::cout << name << " is dead!" << std::endl;
		} else {
			std::cout << name << " has no energy!" << std::endl;
		}
		return ;
	}
	std::cout << "FragTrap " << this->name << " said. 'Give me High five!'" << std::endl;
}
