/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/21 22:26:12 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char *argv[])
{
	PhoneBook	phoneBook;
	std::string	command;
	
	
	while (1)
	{
		std::cout << "Command[ADD|SEARCH|EXIT]:";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			phoneBook.add();
		if (command == "SEARCH")
			phoneBook.search();
	}
	return (0);
}