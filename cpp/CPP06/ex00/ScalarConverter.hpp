/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:41:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/05 10:35:05 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>
#include <limits>
#include <cctype>


#define RESET		"\033[0m"
#define BRED		"\033[1;31m"
#define BGREEN		"\033[1;32m"
#define BYELLOW		"\033[1;33m"
#define BBLUE		"\033[1;34m"
#define BMAGENTA	"\033[1;35m"
#define BCYAN		"\033[1;36m"
#define BORANGE		"\033[1;38;5;208m"
#define BPINK		"\033[1;38;5;213m"
#define BPURPLE		"\033[1;38;5;57m"
#define BTEAL		"\033[1;38;5;30m"



class ScalarConverter
{
	public :

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);

	static void convert(std::string input);
	static bool isStringDigit(std::string input);
	
	static void printChar(int c);
	static void printNan();
	static void printInf(bool negative);
	static void printFloat(float f);
	static void printDouble(double d);

	static void convertChar(std::string input);
	static void convertInt(std::string input);
	static void convertFloat(std::string input);
	static void convertDouble(std::string input);
};



#endif
