/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:01:59 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/11 18:57:24 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstddef>
#include <vector>
#include <limits>
#include <stdexcept>
#include <algorithm>


class Span
{
	private :
		unsigned int _N;
		unsigned int _currentN;
		std::vector<unsigned int> _tab;

	public :
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span& operator=(const Span &other);

		void addNumber(unsigned int add);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif
