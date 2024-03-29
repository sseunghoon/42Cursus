/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/23 17:58:43 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clapDefault;
	ClapTrap clap1("clap1");
	ClapTrap clap2("clap2");
	ClapTrap clap3("clap3");
	ClapTrap clap4("clap4");

	for (int i = 0; i < 5; i++) {
		clap1.attack("clap2");
		clap2.takeDamage(0);
		clap2.attack("clap1");
		clap1.takeDamage(0);
	}
	std::cout << "=============================================================" << std::endl;
	for (int i = 0; i < 5; i++) {
		clap1.beRepaired(1);
		clap2.beRepaired(1);
	}
	std::cout << "=============================================================" << std::endl;
	clap1.attack("clap2");
	clap2.attack("clap1");
	clap1.beRepaired(1);
	clap2.beRepaired(1);
	std::cout << "=============================================================" << std::endl;
	clap3.takeDamage(10);
	clap4.takeDamage(10);
	clap3.attack("clap4");
	clap4.attack("clap3");
	clap3.beRepaired(1);
	clap4.beRepaired(1);

	return (0);
}