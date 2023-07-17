/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:30:24 by songseunghu       #+#    #+#             */
/*   Updated: 2023/07/17 14:45:53 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		class FormNotExistException : public std::exception {
			public:
				const char* what() const throw();
		};

	public:
		Intern();
		Intern(Intern &intern);
		Intern& operator=(Intern& intern);
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);
};

#endif