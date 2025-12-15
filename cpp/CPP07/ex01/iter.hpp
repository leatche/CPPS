/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:01:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/02 12:03:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename F>

void iter(T *array, const size_t size, F function)
{
	size_t i = 0;
	while (i < size)
	{
		function(array[i]);
		i++;
	}
}
#endif
