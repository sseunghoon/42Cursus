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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "Dog's Type: " << j->getType() << " " << std::endl;
		std::cout << "Cat's Type: " << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n==============================\n" << std::endl;

	{
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();

		std::cout << "WrongCat's Type: " << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		meta->makeSound();

		delete meta;
		delete i;
	}

	return 0;
}