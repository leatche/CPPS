/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:01:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/02/09 14:29:26 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	Ford_Johnson a;

	try
	{
		size_t size = a.pars_av(ac, av);
		int result_deque = a.deque_algo();
		int result_vector = a.vector_algo();
		a.print_deque();
		a.print_vector(); 
		std::cout << "Time to process a range of " << size << " elements with std::deque : " << result_deque << "us" << std::endl;
		std::cout << "Time to process a range of " << size << " elements with std::vector : " << result_vector << "us" << std::endl;

	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
}
