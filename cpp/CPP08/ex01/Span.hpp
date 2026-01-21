/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:01:59 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/20 16:32:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP


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
		std::vector<unsigned int> _tab;

	public :
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span& operator=(const Span &other);

		void addNumbers(unsigned int add);
		void addNumbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		void printVector();

};

#endif
