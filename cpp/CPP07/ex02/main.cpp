/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/29 15:24:59 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	try
	{
		std::cout << "Test de la fonction size" << std::endl;

		Array<int> first(5);

		for (size_t i = 0; i < first.size(); ++i)
			first[i] = i * 10;
		
		for (size_t i = 0; i < first.size(); ++i)
			std::cout << first[i] << " ";

		std::cout << std::endl;
		std::cout << "The size is " << first.size() << std::endl;
		std::cout << "The value at index 2 is " << first[2] << std::endl;
		std::cout << first[6] << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		int *a = new int();
		std::cout << std::endl;
		std::cout << " Test du sujet : int *a = new int() => " << *a << std::endl;
		

		std::cout << std::endl;
		std::cout << " Test du constructeur de copie " << std::endl;
		
		Array<int> c(5);
		c[0] = 1;
		Array<int> b(c);
		b[0] = 999;
		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;

		std::cout << std::endl;
		std::cout << " Test de l'opérateur égal " << std::endl;

		
		Array<int> d;
		d = c;
		d[0] = 777;
		std::cout << "d[0] = " << d[0] << std::endl;
		std::cout << "c[0] = " << c[0] << std::endl;

		std::cout << b[42] << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	

return 0;
}

