/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/02 12:03:47 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void increment(int &x)
{
	++x;
}

void print(int &x)
{
	std::cout << x << " ";
	std::cout << std::endl;
}

int main( void )
{
	int array[] = {1, 2, 3, 4};

	iter(array, 4, increment);
	iter(array, 4, print);
	std::cout << std::endl;
	iter(array, 4, increment);
	iter(array, 3, print);
	std::cout << std::endl;
	iter(array, 4, increment);
	iter(array, 2, print);
	std::cout << std::endl;
	iter(array, 4, increment);
	iter(array, 1, print);
	return 0;
}
