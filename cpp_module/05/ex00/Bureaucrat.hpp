#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		int grade;

		class GradeTooHighException : public std::exception {
			public:
				const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what(void) const throw();
		};

    public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		void checkGrade(int futureGrade) const;

		const std::string& getName() const;
		const int getGrade() const;

		void incrementGrade();
		void decrementGrade();
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &bc);

#endif
