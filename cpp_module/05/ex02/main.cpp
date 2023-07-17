/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/07/17 14:53:47 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat lowBC("lowBC", 150);
	Bureaucrat highBC("highBC", 1);
	Bureaucrat scBC1("scBC1", 138);
	Bureaucrat scBC2("scBC2", 137);
	Bureaucrat rrBC1("rrBC1", 46);
	Bureaucrat rrBC2("rrBC2", 45);
	Bureaucrat ppBC1("ppBC1", 6);
	Bureaucrat ppBC2("ppBC2", 5);

	ShrubberyCreationForm scForm("scTarget");
	RobotomyRequestForm rrForm("rrTarget");
	PresidentialPardonForm ppForm("ppTarget");

	std::cout << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "=== Shrubbery Test ===" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << std::endl;
	
	std::cout << "lowBC tries to sign scForm" << std::endl;
	lowBC.signForm(scForm);
	std::cout << std::endl;

	std::cout << "highBC tries to execute scForm" << std::endl;
	highBC.executeForm(scForm);
	std::cout << std::endl;

	std::cout << "scBC1 tries to sign scForm" << std::endl;
	scBC1.signForm(scForm);
	std::cout << std::endl;

	std::cout << "scBC1 tries to execute scForm" << std::endl;
	scBC1.executeForm(scForm);
	std::cout << std::endl;

	std::cout << "scBC2 tries to sign scForm" << std::endl;
	scBC2.signForm(scForm);
	std::cout << std::endl;

	std::cout << "scBC2 tries to execute scForm" << std::endl;
	scBC2.executeForm(scForm);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "=== Robotomy Test ===" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << std::endl;

	std::cout << "lowBC tries to sign rrForm" << std::endl;
	lowBC.signForm(rrForm);
	std::cout << std::endl;

	std::cout << "highBC tries to execute rrForm" << std::endl;
	highBC.executeForm(rrForm);
	std::cout << std::endl;

	std::cout << "rrBC1 tries to sign rrForm" << std::endl;
	rrBC1.signForm(rrForm);
	std::cout << std::endl;

	std::cout << "rrBC1 tries to execute rrForm" << std::endl;
	rrBC1.executeForm(rrForm);
	std::cout << std::endl;

	std::cout << "rrBC2 tries to sign rrForm" << std::endl;
	rrBC2.signForm(rrForm);
	std::cout << std::endl;

	std::cout << "rrBC2 tries to execute rrForm" << std::endl;
	rrBC2.executeForm(rrForm);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << "=== Presidential Test ===" << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << std::endl;

	std::cout << "lowBC tries to sign ppForm" << std::endl;
	lowBC.signForm(ppForm);
	std::cout << std::endl;

	std::cout << "highBC tries to execute ppForm" << std::endl;
	highBC.executeForm(ppForm);
	std::cout << std::endl;

	std::cout << "ppBC1 tries to sign ppForm" << std::endl;
	ppBC1.signForm(ppForm);
	std::cout << std::endl;
	
	std::cout << "ppBC1 tries to execute ppForm" << std::endl;
	ppBC1.executeForm(ppForm);
	std::cout << std::endl;

	std::cout << "ppBC2 tries to sign ppForm" << std::endl;
	ppBC2.signForm(ppForm);
	std::cout << std::endl;

	std::cout << "ppBC2 tries to execute ppForm" << std::endl;
	ppBC2.executeForm(ppForm);
	std::cout << std::endl;

	return (0);
}