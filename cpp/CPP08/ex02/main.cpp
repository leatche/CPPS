/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:11:06 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/26 11:37:55 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	//////////////////////// MAIN SUBJECT //////////////////////////////////////

	std::cout << BRED << "MAIN SUBJECT" << RESET << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << BCYAN << "TOP METHOD : "  << RESET << "(the element at the top of the stack) = "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout << BCYAN << "A POP HAS BEEN DONE :"  << RESET << " (removes the element at the top of the stack) = " << RESET << mstack.top() << std::endl;
	std::cout <<  BGREEN << "The size is now : " << RESET << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterators it = mstack.begin();
	MutantStack<int>::iterators ite = mstack.end();
	++it;
	--it;
	std::cout << BYELLOW << "The final stack : " << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	//////////////////////// CONSTANT AND REVERSE ITERATORS ////////////////////////

	std::cout << std::endl;
	std::cout << BRED << "CONSTANT AND REVERSE ITERATORS" << RESET << std::endl << std::endl;

	const MutantStack<int> constStack(mstack);

	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	std::cout << BYELLOW << "The final stack with const iterator  :" << RESET << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	//////////////////////// REVERSE ITERATORS ////////////////////////

	std::cout << std::endl;
	std::cout << BRED << "REVERSE ITERATORS" << RESET << std::endl << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << BYELLOW << "The final stack reverse iterator (top to bottom) :" << RESET << std::endl;

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return (0);
}
