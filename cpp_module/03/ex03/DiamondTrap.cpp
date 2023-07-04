/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/07/04 02:02:01 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap() {
	name = "default";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap constructor called: " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called: " << this->name << std::endl;
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
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << name << "has no energyPoints or hitPoints!" << std::endl;
		return ;
	}

	std::cout << "My name is " << name 
		<< ", and ClapTrap name is " 
		<< ClapTrap::name << std::endl;
}