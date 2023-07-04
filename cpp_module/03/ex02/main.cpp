/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/04 01:42:48 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap fragDefault;
	FragTrap frag1("frag1");
	FragTrap frag2("frag2");

	fragDefault.highFivesGuys();
	frag1.attack("frag2");
	frag2.takeDamage(30);
	frag2.attack("frag1");
	frag1.takeDamage(30);
	frag1.beRepaired(1);
	frag2.beRepaired(1);
	
	std::cout << "=============================================================" << std::endl;
	
	frag1.takeDamage(100);
	frag2.takeDamage(100);
	frag1.attack("frag2");
	frag2.attack("frag1");
	frag1.beRepaired(1);
	frag2.beRepaired(1);

	std::cout << "=============================================================" << std::endl;
	
	ClapTrap *upCasting = new FragTrap("upCasting");
	upCasting->attack("fragDefault");
	fragDefault.takeDamage(30);
	delete upCasting;

	return (0);
}