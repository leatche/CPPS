/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:04 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/20 16:21:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <stdexcept>
#include <algorithm>


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

template <typename T>

void easyfind(const T &a, int b)
{
	typename T::const_iterator it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		std::cout << "I find the occurrence " << *it << std::endl;
	else
	{
		std::cerr << BRED << b << " : ";
		throw::std::out_of_range("occurrence isn't found !");
	}
		
}

#endif
