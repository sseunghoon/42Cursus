/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/21 19:50:32 by songseunghu      ###   ########.fr       */
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
		std::cin >> command;
		if (command.compare("EXIT"))
			break ;
		if (command.compare("ADD"))
			phoneBook.Add();
		if (command.compare("SEARCH"))
			phoneBook.Search();
	}
	return (0);
}