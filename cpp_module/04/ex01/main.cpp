/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/04 03:57:13 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j; // should not create a leak
		delete i;
	}
	{
		Animal *arr[4];
		for (int i = 0; i < 2; i++) {
			arr[i] = new Dog();
		}
		for (int i = 2; i < 4; i++) {
			arr[i] = new Cat();
		}
		delete[] arr;
	}

	return 0;
}