/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:07:02 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/07 18:45:27 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Invalid number of argument, 1 argument expected" << std::endl;
		return (1);
	}
	ScalarConverter::convert(std::string(av[1]));
	return (0);
}
