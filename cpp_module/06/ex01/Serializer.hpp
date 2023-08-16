#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data {
	std::string str;
}	Data;

class Serializer {
    private:
    	Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
