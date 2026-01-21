/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/13 12:53:50 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: You're only allowed to put one argument !" << std::endl;
		return 1;
	}
	
	RPN a;

	try
	{
		int result = a.calculator_RPN(av[1]);
		std::cout << " The result of the operation ' " << av[1] << " ' is : " << std::endl << BGREEN << result << RESET << " ! " << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
}
