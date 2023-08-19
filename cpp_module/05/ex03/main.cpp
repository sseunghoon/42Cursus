/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/17 14:52:48 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat highBC("highBC", 1);

	std::cout << "\n======================\n" << std::endl;

	AForm* scForm = intern.makeForm("shrubbery creation", "scTarget");
	AForm* rrForm = intern.makeForm("robotomy request", "rrTarget");
	AForm* ppForm = intern.makeForm("presidential pardon", "ppTarget");

	std::cout << "\n======================" << std::endl;
	std::cout << "=== Shrubbery Test ===" << std::endl;
	std::cout << "======================\n" << std::endl;

	if (scForm) {
		highBC.signForm(*scForm);
		highBC.executeForm(*scForm);
	} else {
		std::cout << "scForm is NULL" << std::endl;
	}

	std::cout << "\n======================" << std::endl;
	std::cout << "=== Robotomy Test ====" << std::endl;
	std::cout << "======================\n" << std::endl;

	if (rrForm) {
		highBC.signForm(*rrForm);
		highBC.executeForm(*rrForm);
	} else {
		std::cout << "rrForm is NULL" << std::endl;
	}

	std::cout << "\n======================" << std::endl;
	std::cout << "=== Presidential Test ===" << std::endl;
	std::cout << "======================\n" << std::endl;

	if (ppForm) {
		highBC.signForm(*ppForm);
		highBC.executeForm(*ppForm);
	} else {
		std::cout << "ppForm is NULL" << std::endl;
	}

	std::cout << "\n======================" << std::endl;
	std::cout << "=== Failure Test ===" << std::endl;
	std::cout << "======================\n" << std::endl;

	AForm* failureForm = intern.makeForm("failure", "failure");
	if (failureForm) {
		highBC.signForm(*failureForm);
		highBC.executeForm(*failureForm);
	} else {
		std::cout << "failureForm is NULL" << std::endl;
	}


	return (0);
}