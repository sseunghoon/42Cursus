/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/23 17:57:57 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavDefault;
	ScavTrap scav1("scav1");
	ScavTrap scav2("scav2");

	scavDefault.guardGate();
	scav1.attack("scav2");
	scav2.takeDamage(20);
	scav2.attack("scav1");
	scav1.takeDamage(20);
	scav1.beRepaired(1);
	scav2.beRepaired(1);
	
	std::cout << "=============================================================" << std::endl;
	
	scav1.takeDamage(100);
	scav2.takeDamage(100);
	scav1.attack("scav2");
	scav2.attack("scav1");
	scav1.beRepaired(1);
	scav2.beRepaired(1);

	std::cout << "=============================================================" << std::endl;
	
	ClapTrap *upCasting = new ScavTrap("upCasting");
	upCasting->attack("scavDefault");
	delete upCasting;

	return (0);
}