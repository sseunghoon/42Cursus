/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/23 20:09:07 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondDefault;
	DiamondTrap diamond1("diamond1");
	DiamondTrap diamond2("diamond2");

	diamondDefault.highFivesGuys();
	diamond1.attack("diamond2");
	diamond2.takeDamage(20);
	diamond2.attack("diamond1");
	diamond1.takeDamage(20);
	diamond1.beRepaired(1);
	diamond2.beRepaired(1);
	
	std::cout << "=============================================================" << std::endl;
	
	diamond1.takeDamage(100);
	diamond2.takeDamage(100);
	diamond1.attack("diamond2");
	diamond2.attack("diamond1");
	diamond1.beRepaired(1);
	diamond2.beRepaired(1);

	std::cout << "=============================================================" << std::endl;
	
	ClapTrap *upCasting = new DiamondTrap("upCasting");
	upCasting->attack("diamondDefault");
	delete upCasting;

	return (0);
}