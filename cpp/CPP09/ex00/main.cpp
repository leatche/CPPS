/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:39 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/06 11:09:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: You're only allowed to put one argument !" << std::endl;
		return 1;
	}

	Bitcoin btc;
	
	try
	{
		btc.transfer_data_to_map();
		btc.compare_input_to_map(av[1]);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
}
