/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/21 18:43:11 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.str = "Hello World!";

	std::cout << "Before Serialized: " << &data << std::endl;


	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "After Serialized: " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);
	std::cout << "After Deserialized: " << ptr << std::endl;

	return 0;
}