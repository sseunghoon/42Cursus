/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:33:57 by songseunghu       #+#    #+#             */
/*   Updated: 2023/03/22 03:24:50 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	std::cout << this->name << "attacks with his " << this->weapon->getType() << std::endl;
}