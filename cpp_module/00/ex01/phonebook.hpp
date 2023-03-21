/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:06 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/21 16:22:11 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class PhoneBook
{
	private:
		int		index;
		char	first_name[10];
		char	last_name[10];
		char	nick_name[10];
		char	phone_number[10];
		char	darkest_secret[10];
	public:
		void	print_self();
}