/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/11 23:09:09 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	try
	{
		std::cout << BGREEN << "Function size tests : " << RESET << std::endl;

		Array<int> first(5);

		for (size_t i = 0; i < first.size(); ++i)
			first[i] = i * 10;
		
		for (size_t i = 0; i < first.size(); ++i)
			std::cout << first[i] << " ";

		std::cout << std::endl;
		std::cout << "The size of the array is " << BBLUE << first.size() << RESET << std::endl;
		std::cout << "The value at index 2 is " << BBLUE << first[2] << RESET << std::endl;
		std::cout << first[6] << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << BRED << e.what() << RESET << std::endl;
	}


	try
	{
		std::cout << std::endl;
		std::cout << BGREEN << "Subject test : "<< RESET << std::endl;
		Array<int> z(5); // representation de la ligne int *a = new int();
		int * a = new int();
		std::cout << "The array at index 2 with no initializion is equal to : " << BBLUE << z[2] << RESET << std::endl;
		std::cout << "a is equal to " << BBLUE << *a << RESET << std::endl;


		std::cout << std::endl;
		std::cout << BGREEN << "Copy constructor test" << RESET << std::endl;
		Array<int> c(5);
		c[0] = 1;
		Array<int> b(c);
		std::cout << "The array that has been copied is equal to c[0] = " << BBLUE << c[0] << RESET << std::endl;
		std::cout << "The array that copied is equal to b[0] = " << BBLUE << b[0] << RESET << std::endl;
		b[0] = 999;
		std::cout << "With a new affectation of value, b[0] = " << BBLUE << b[0] << RESET << std::endl;
		


		std::cout << std::endl;
		std::cout << BGREEN <<  "Equal operator test " << RESET << std::endl;
		Array<int> d;
		d = c;
		d[0] = 777;
		std::cout << "d[0] = " << BBLUE << d[0] << RESET << std::endl;
		std::cout << "c[0] = " << BBLUE << c[0] << RESET << std::endl;


		std::cout << std::endl;
		std::cout << BGREEN <<  "Equal operator test with check of the size" << RESET << std::endl;
		Array<int> e(9);
		int size_start = e.size();
		e = c;
		int final_size = e.size();
		std::cout << "size of e : " << BBLUE << size_start << RESET << std::endl;
		std::cout << "new size of e : " << BBLUE << final_size << RESET << std::endl;

		std::cout << std::endl;
		std::cout << BGREEN <<  "Const array test " << RESET << std::endl;
		const Array<int> m(3);
		std::cout << "The value of an const array at index 0 : " << BBLUE << m[0] << RESET << std::endl;

		std::cout << b[42] << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}

