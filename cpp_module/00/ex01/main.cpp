/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/23 10:56:10 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;
	
	
	while (true)
	{
		command = get_input("Command[ADD|SEARCH|EXIT]:");
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			phoneBook.add();
		if (command == "SEARCH")
			phoneBook.search();
	}
	return (0);
}