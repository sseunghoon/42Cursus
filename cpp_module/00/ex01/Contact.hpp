#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

class Contact {
	public:
		Contact();
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		void		printShort();
		void		printSelf();
		std::string	resizing(std::string str);
		~Contact();
};

#endif