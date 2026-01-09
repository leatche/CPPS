/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:34 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/03 18:56:26 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base* generate(void)
{

	int res = rand() % 3;
	if (res == 0)
	{
		std::cout << BCYAN << "A has been choosing" << RESET << std::endl;
		Base* p = new A();
		return (p);
	}
	else if (res == 1)
	{
		std::cout << BGREEN << "B has been choosing" << RESET << std::endl;
		Base* p = new B();
		return (p);
	}
	else
	{
		std::cout << BRED << "C has been choosing" << RESET << std::endl;
		Base* p = new C();
		return (p);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
       	std::cout << BCYAN << "the object pointed by p is A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
    	std::cout << BGREEN << "the object pointed by p is B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BRED << "the object pointed by p is C" << RESET << std::endl;

}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
       	std::cout << BCYAN << "the object referenced by p is A" << RESET << std::endl;
        return;
    } catch (...){}

    try {
        (void)dynamic_cast<B&>(p);
              	std::cout << BGREEN << "the object referenced by p is B" << RESET << std::endl;

        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << BRED << "the object referenced by p is C" << RESET << std::endl;
        return;
    } catch (...) {}
}
