/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/16 17:21:34 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    Base *base = NULL;

    std::srand((unsigned int)std::time(NULL));
    int num = std::rand() % 3;
    
    switch (num) {
        case 0:
            base = new A;
            std::cout << "A gernerated" << std::endl;
            break;
        case 1:
            base = new B;
            std::cout << "B gernerated" << std::endl;
            break;
        case 2:
            base = new C;
            std::cout << "C gernerated" << std::endl;
            break;
    }
    return base;
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "identify(pointer) : A class" << std::endl;
	else if (b)
		std::cout << "identify(pointer) : B class" << std::endl;
	else if (c)
		std::cout << "identify(pointer) : C class" << std::endl;
	else
		std::cout << "identify(pointer) : Base class" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&> (p);
        (void)a;
		std::cout << "identify(reference) : A class" << std::endl;
        return ;
    } catch( const std :: bad_cast &e ) {}
	
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "identify(reference) : B class" << std::endl;
        return ;
    } catch( const std :: bad_cast &e ) {}
	
    try {
        C& c =  dynamic_cast<C&>(p);
        (void)c;
        std::cout << "identify(reference) : C class" << std::endl;
        return ;
    } catch( const std :: bad_cast &e ) {}

    std::cout << "identify(reference) : Base class" << std::endl;
}

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	

	return 0;
}