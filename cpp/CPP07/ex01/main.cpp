/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/11 22:55:25 by tcherepoff       ###   ########.fr       */
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


void printt(const int &x)
{
	std::cout << x << " ";
	std::cout << std::endl;
}

int main( void )
{
	std::cout << "INT TESTS " << std::endl;
	int array[] = {1, 2, 3, 4};

	iter(array, 4, increment);
	std::cout << "1234 with +1 to every one :" << std::endl;
	iter(array, 4, print);
	std::cout << std::endl;
	iter(array, 4, increment);
	std::cout << "2345 with +1 to every one and size 3 :" << std::endl;
	iter(array, 3, print);
	std::cout << std::endl;
	iter(array, 4, increment);
std::cout << "345 with +1 to every one and size 2 :" << std::endl;
	iter(array, 2, print);
	std::cout << std::endl;
	iter(array, 4, increment);
	std::cout << "45 with +1 to every one and size 1 :" << std::endl;
	iter(array, 1, print);
	
	std::cout << std::endl;
	std::cout << "CONST TESTS " << std::endl;
	const int mi[] = {1, 2, 3, 4};
	std::cout << "just print the const array :" << std::endl;
	iter(mi, 4, printt);

	return 0;
}
