/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:58:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/11 22:21:02 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
{
	//////////////////////////// main subject //////////////////////////////////
std::cout << "SUBJECT TESTS " << std::endl;
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

////////////////////////////////// own tests //////////////////////////////////c

std::cout << std::endl;
std::cout << "OWN TESTS " << std::endl;

std::string g = "hi";
std::string h = "hij";

std::cout << "min( hi, hij ) = " << ::min( g, h ) << std::endl;
std::cout << "max( hi, hij ) = " << ::max( g, h ) << std::endl;

const int e = 1;
const int f = 2;

std::cout << "min( 1, 2 ) = " << ::min( e, f ) << std::endl;
std::cout << "max( 1, 2 ) = " << ::max( e, f ) << std::endl;

std::cout << "without any object, min(3, 7) = " << ::min(3, 7) << std::endl;

return 0;
}
