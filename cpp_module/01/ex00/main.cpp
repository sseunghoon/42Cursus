/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/05/25 00:49:58 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(int argc, char *argv[])
{
	Zombie	stack1 = Zombie("stack1");
	Zombie	stack2 = Zombie("stack2");

	Zombie	*heap1 = newZombie("heap1");
	Zombie	*heap2 = newZombie("heap2");

	heap1->announce();
	heap2->announce();

	delete(heap1);
	delete(heap2);

	randomChump("stack3");
	
	return (0);
}