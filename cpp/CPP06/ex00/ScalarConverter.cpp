/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:40:58 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/07 18:52:41 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
	bool is_char = input.size() == 1 && isdigit(input[0]) == false;
	bool is_double = !is_char && input.find_first_of('.') != std::string::npos && input.find_first_of('.') == input.find_last_of('.');
	bool is_float = is_double && input.find_first_of('f') != std::string::npos && input.find_first_of('f') == input.find_last_of('f');
	if (is_float)
		is_double = false;
	bool is_int = !is_double && !is_float && !is_char && isStringDigit(input);

	if (!input.compare("nan") || !input.compare("nanf"))
		return printNan();
	if (!input.compare("inf") || !input.compare("+inf")
	|| !input.compare("inff") || !input.compare("+inff"))
		return printInf(false);
	if (!input.compare("-inf") || !input.compare("-inff"))
		return printInf(true);

	if (is_char)
		return convertChar(input);
	else if (is_int)
		return convertInt(input);
	else if (is_float)
		return convertFloat(input);
	else if (is_double)
		return convertDouble(input);
	else
		return printNan();
	std::cout << std::endl;
}


bool ScalarConverter::isStringDigit(std::string input)
{
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (i < input.size())
	{
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

// ########################################################################## //
// #                              PRINT                                     # //
// ########################################################################## //
void ScalarConverter::printChar(int c)
{
	if (c > 255 || c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}

void ScalarConverter::printNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::printInf(bool negative)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (negative)
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << d;
	if (d == static_cast<int>(d))
    	std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

// ########################################################################## //
// #                              CONVERT                                   # //
// ########################################################################## //

void ScalarConverter::convertChar(std::string input)
{
	char c = input[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(i);
	std::cout << "int: " << i << std::endl;
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertInt(std::string input)
{
	int i;
	if (input.length() <= 12)
		i = std::atoi(input.c_str());
	else
	{
		std::cout << "Int is out of range" << std::endl ;
		return ;
	}
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(i);
	std::cout << "int: " << i << std::endl;
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertFloat(std::string input)
{
	float f = std::strtof(input.c_str(), NULL);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(i);
	std::cout << "int: " << i << std::endl;
	printFloat(f);
	
	printDouble(d);
}

void ScalarConverter::convertDouble(std::string input)
{
	double d = std::strtod(input.c_str(), NULL);
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);

	printChar(i);
	if (d <= std::numeric_limits<int>::min() || d >= std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	printFloat(f);
	printDouble(d);
}


// ########################################################################## //
// #                              CANONIQUE                                 # //
// ########################################################################## //

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &n)
{
	*this = n;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &n)
{
	(void)n;
	return (*this);
}
