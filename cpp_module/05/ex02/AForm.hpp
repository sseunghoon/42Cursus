#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
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
		class NotSignedException : public std::exception {
			public:
				const char * what(void) const throw();
		};

    public:
    	AForm();
		AForm(std::string _name, int signGrade, int exeGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		void beSigned(const Bureaucrat &bc);
		void checkException() const;
		void isExecutable(const Bureaucrat &executor) const;

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExeGrade() const;
		
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator << (std::ostream &out, const AForm &AForm);


#endif
