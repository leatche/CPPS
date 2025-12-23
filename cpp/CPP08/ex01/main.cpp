/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:39:00 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/23 20:30:20 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	srand(time(NULL));
	try
	{
		//////////////////// manual version ////////////////////////////////

		std::cout << BGREEN << "manual version ; size 5" << RESET << std::endl;
		Span tab1(5);

		tab1.addNumber(8);
		tab1.addNumber(3);
		tab1.addNumber(55);
		tab1.addNumber(1);
		tab1.addNumber(108);

		tab1.printVector();

		std::cout << BCYAN << "the longest span in the tab is ";
		std::cout << BYELLOW << tab1.longestSpan() << RESET << std::endl;
		std::cout << BCYAN << "and the shortest is ";
		std::cout << BYELLOW << tab1.shortestSpan() << RESET << std::endl;


		//////////////////// rand on 99 version ////////////////////////////////

		std::cout << std::endl;
		std::cout << BGREEN << "rand version ; size 99" << RESET << std::endl;
		Span tab2(99);

		for (int i = 0; i < 99; ++i)
			tab2.addNumber(static_cast<unsigned int>(rand() % 100000));

		tab2.printVector();
		std::cout << BCYAN << "the longest span in the tab is ";
		std::cout << BYELLOW << tab2.longestSpan() << RESET << std::endl;
		std::cout << BCYAN << "and the shortest is ";
		std::cout << BYELLOW << tab2.shortestSpan() << RESET << std::endl;

		//////////////////// rand on 20000 version ////////////////////////////////

		std::cout << std::endl;
		std::cout << BGREEN << "addNumbers version ; size 20000" << RESET << std::endl;
		Span tab3(20000);

		std::vector<unsigned int> tmp;
		for (int i = 0; i < 20000; ++i)
			tmp.push_back(rand());

		tab3.addNumbers(tmp.begin(), tmp.end());

		std::cout << BCYAN << "the longest span in the tab is ";
		std::cout << BYELLOW << tab3.longestSpan() << RESET << std::endl;
		std::cout << BCYAN << "and the shortest is ";
		std::cout << BYELLOW << tab3.shortestSpan() << RESET << std::endl;

		tab3.addNumber(8);
	}
	catch(const std::length_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
