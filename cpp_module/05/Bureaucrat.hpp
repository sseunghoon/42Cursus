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

    public:
    	Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void increment(int amount);
		void decrement(int amount);
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &bc);

#endif
