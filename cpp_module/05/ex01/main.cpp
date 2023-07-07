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

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat t1("t1", 151);
	} catch (const std::exception &e) {
		std::cerr << "t1: " << e.what() << std::endl;
	}

	try {
		Bureaucrat t2("t2", 150);
		t2.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "t2: " << e.what() << std::endl;
	}

	try {
		Bureaucrat t3("t3", 1);
		t3.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "t3: " << e.what() << std::endl;
	}

	Bureaucrat t4("t4", 1);
	try {
		t4.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "t4: " << e.what() << std::endl;
	}
	std::cout << t4 << std::endl;

	return 0;
}