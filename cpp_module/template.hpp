#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

class Template {
	public:
		Template();
		Template(const Template& copy);
		Template& operator=(const Template& copy);
		~Template();
};

#endif