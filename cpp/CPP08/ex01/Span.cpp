/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:01:45 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/11 19:03:31 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _currentN(0)
{

}
Span::Span(unsigned int N) : _N(N), _currentN(0)
{
	_tab.reserve(N);
}
Span::~Span()
{

}
Span::Span(const Span &other) : _N(0), _currentN(0)
{
	*this = other;
}
Span& Span::operator=(const Span &other)
{
	_N = other._N;
	_currentN = other._currentN;
	_tab = other._tab;
	return (*this);
}

void Span::addNumber(unsigned int add)
{
	if (_currentN == _N)
		throw std::length_error("Span is already full");
	_tab.push_back(add);
	_currentN++;
}

unsigned int Span::longestSpan()
{
	std::sort(_tab.begin(), _tab.end());
	return ((_tab.begin() + (_N - 1)) - _tab.begin());
}

unsigned int Span::shortestSpan()
{
	std::sort(_tab.begin(), _tab.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	
	std::vector<unsigned int>::iterator it = _tab.begin();
	std::vector<unsigned int>::iterator end = _tab.end();
	int i = -1;

	/// utiliser iterateur mais pas des i // 
	while (end != it && (it + 2))
	{
		++it;
		unsigned int diff_value;

		diff_value = (it + 1) - it;
		if (diff_value < shortest)
			shortest = diff_value;
	}
	return (shortest);
}
