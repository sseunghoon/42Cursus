/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:33:57 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/28 09:47:02 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	this->name = "default";
	announce();
}

Zombie::Zombie(std::string name) {
	this->name = name;
	announce();
}

Zombie::~Zombie() {
	std::cout << this->name << " Dieee..." << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name) {
	Zombie randomZombie = Zombie(name);
}

Zombie* newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return newZombie;
}