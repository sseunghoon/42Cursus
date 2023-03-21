/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/21 16:23:59 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	add(PhoneBook )

int	main(int argc, char *argv[])
{
	PhoneBook[10]	phoneBook;
	std::string	command;
	
	
	while (1)
	{
		std::cout << "Command:";
		std::cin >> command;
		if (command.compare("EXIT"))
			break ;
		if (command.compare("ADD"))
			add();
		if (command.compare("SEARCH"))
			search();
	}
	return (0);
}