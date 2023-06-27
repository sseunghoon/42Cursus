/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/23 20:49:22 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap() {
	name = "default";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called: " << name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& fixed) {
	std::cout << "DiamondTrap Copy constructor called: " << name << std::endl;
	*this = fixed;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& fixed) {
	std::cout << "DiamondTrap Copy assignment operator called: " << name << std::endl;
	name = fixed.name;
	hitPoints = fixed.hitPoints;
	energyPoints = fixed.energyPoints;
	attackDamage = fixed.attackDamage;
	
	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << name 
		<< ", and ClapTrap name is " 
		<< ClapTrap::name << std::endl;
}