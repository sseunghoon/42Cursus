/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/04 02:00:13 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondDefault;
	DiamondTrap diamond1("diamond1");
	DiamondTrap diamond2("diamond2");

	diamondDefault.highFivesGuys();
	diamondDefault.whoAmI();
	diamond1.whoAmI();
	diamond2.whoAmI();

	diamond1.attack("diamond2");
	diamond2.takeDamage(30);
	diamond2.attack("diamond1");
	diamond1.takeDamage(30);
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
	diamondDefault.takeDamage(30);
	delete upCasting;

	return (0);
}