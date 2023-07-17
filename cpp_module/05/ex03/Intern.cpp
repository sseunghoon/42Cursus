/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:30:11 by songseunghu       #+#    #+#             */
/*   Updated: 2023/07/17 14:45:57 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern &intern) {
	std::cout << "Intern Copy constructor called" << std::endl;
	(void)intern;
}

Intern& Intern::operator=(Intern& intern) {
	std::cout << "Intern Assignation operator called" << std::endl;
	(void)intern;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	selectedName = -1;
	AForm* form = NULL;
	
	for (int i = 0; i < 3; i++) {
		if (names[i].compare(formName) == 0)
			selectedName = i;
	}

	try {
		switch (selectedName) {
			case 0:
				form = new ShrubberyCreationForm(formTarget);
				break;
			case 1:
				form = new RobotomyRequestForm(formTarget);
				break;
			case 2:
				form = new PresidentialPardonForm(formTarget);
				break;
			default:
				throw FormNotExistException();
		}
		std::cout << "Intern makes " << *form << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return form;
}

const char* Intern::FormNotExistException::what() const throw() {
	return "Intern: Form not exist";
}