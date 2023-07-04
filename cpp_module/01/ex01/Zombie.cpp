/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:33:57 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/28 11:01:35 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("default") {
}

Zombie::Zombie(std::string name) : name(name){
}

Zombie::~Zombie() {
	std::cout << this->name << " Dieee..." << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}

void randomChump(std::string name) {
	Zombie randomZombie = Zombie(name);
}

Zombie* newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie(name);
	return newZombie;
}
