/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/16 16:43:50 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.str = "Hello World!";

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "After Serialized: " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);
	std::cout << "After Deserialized: " << ptr->str << std::endl;

	return 0;
}