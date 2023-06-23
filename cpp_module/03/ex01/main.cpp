/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/23 16:43:39 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap c0;
	ClapTrap c1("c1");
	ClapTrap c2("c2");
	ClapTrap c3("c3");
	ClapTrap c4("c4");

	for (int i = 0; i < 5; i++) {
		c1.attack("c2");
		c2.takeDamage(0);
		c2.attack("c1");
		c1.takeDamage(0);
	}
	std::cout << "=============================================================" << std::endl;
	for (int i = 0; i < 5; i++) {
		c1.beRepaired(1);
		c2.beRepaired(1);
	}
	std::cout << "=============================================================" << std::endl;
	c1.attack("c2");
	c2.attack("c1");
	c1.beRepaired(1);
	c2.beRepaired(1);
	std::cout << "=============================================================" << std::endl;
	c3.takeDamage(10);
	c4.takeDamage(10);
	c3.attack("c4");
	c4.attack("c3");
	c3.beRepaired(1);
	c4.beRepaired(1);

	return (0);
}