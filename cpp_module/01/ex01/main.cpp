/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/28 11:05:22 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie("stackZombie");
	zombie.announce();

	Zombie *zombies = zombieHorde(5, "heapZombie");

	for (int i = 0; i < 5; i++) {
		zombies[i].announce();
	}
	
	delete[] zombies;
	
	return (0);
}
