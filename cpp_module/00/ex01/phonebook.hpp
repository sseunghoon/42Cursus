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

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		Contact	contacts[8];
		int		index;
		void	printAll();
		void	search();
		void	add();
		~PhoneBook();
};

#endif