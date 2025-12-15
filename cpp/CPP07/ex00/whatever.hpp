/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:01:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/23 11:29:48 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>

void swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>

T min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>

T max(T &a, T &b)
{
	return (a > b ? a : b);
}
