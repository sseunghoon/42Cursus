#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
    public:
    	Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();

		std::string getIdea(int idx) const;
		void setIdea(std::string idea, int idx);
};

#endif
