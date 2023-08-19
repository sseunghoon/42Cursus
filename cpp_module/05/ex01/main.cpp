/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/17 14:20:44 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "================================\n\n";
	{
		try {
			Form a("A", 1, 20);
			std::cout << a << std::endl;
			Form b("B", 1, 151);
			std::cout << b << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n================================\n\n";
	{
		try {
			Form a("A", 1, 150);
			std::cout << a << std::endl;
			Form b("B", 0, 150);
			std::cout << b << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n================================\n\n";
	{
		Form form("testForm", 10, 20);
		Bureaucrat bc("testBC", 11);
		
		try {
			std::cout << form << std::endl;
			std::cout << bc << std::endl;
			bc.signForm(form);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\n================================\n\n";
		try {
			bc.incrementGrade();
			bc.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}