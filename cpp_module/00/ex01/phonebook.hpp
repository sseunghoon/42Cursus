/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:06 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/21 21:54:23 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <sstream>
#include "Contact.hpp"

class PhoneBook {
	private:
		int		index;
		Contact	contacts[8];
		void	printAll();

	public:
		PhoneBook();
		void	search();
		void	add();
		~PhoneBook();
};

int	ft_stoi(std::string str);
std::string	get_input(std::string str);

#endif