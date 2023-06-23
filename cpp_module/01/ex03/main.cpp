/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/22 01:43:50 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(int argc, char *argv[])
{
	{
		Weapon club = Weapon("crude spiked club");
    	HumanA bob("Bob", club);
    	bob.attack();
    	club.setType("some other type of club");
    	bob.attack();
	}
	{
    	Weapon club = Weapon("crude spiked club");
    	HumanB jim("Jim");
    	jim.setWeapon(club);
    	jim.attack();
    	club.setType("some other type of club");
    	jim.attack();
	}
	
	return (0);
}