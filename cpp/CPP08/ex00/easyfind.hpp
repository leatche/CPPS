/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:04 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/29 17:38:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>

void easyfind(T &a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		std::cout << "I find the occurrence " << *it << std::endl;
	else
		throw::std::out_of_range("There isn't any occurence ");
}

#endif
