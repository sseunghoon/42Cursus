#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int exeGrade;

		class GradeTooHighException : public std::exception {
			public:
				const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what(void) const throw();
		};

    public:
    	Form();
		Form(std::string _name, int signGrade, int exeGrade);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		void beSigned(const Bureaucrat &bc);
		void checkException() const;

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExeGrade() const;
};

std::ostream& operator << (std::ostream &out, const Form &form);


#endif
