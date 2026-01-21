/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:01:45 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/20 16:32:08 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{

}
Span::Span(unsigned int N) : _N(N)
{
	_tab.reserve(N);
}
Span::~Span()
{

}
Span::Span(const Span &other) : _N(0)
{
	*this = other;
}
Span& Span::operator=(const Span &other)
{
	_N = other._N;
	_tab = other._tab;
	return (*this);
}

void Span::addNumbers(unsigned int add)
{
	if (_tab.size() >= _N)
		throw std::length_error("Span is already full");
	_tab.push_back(add);
}

unsigned int Span::longestSpan()
{
	if (_tab.empty() || _tab.size() < 2)
		std::length_error("you can't find the longest span. There isn't enough number store");
	
	std::vector<unsigned int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *(tmp.begin()));
}

unsigned int Span::shortestSpan()
{
	if (_tab.empty() || _tab.size() < 2)
		std::length_error("you can't find the shortest span. There isn't enough number store");
	
	std::vector<unsigned int> tmp = _tab;
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();

	for (std::vector<unsigned int>::iterator it = tmp.begin(); it + 1 != tmp.end(); ++it)
	{
		unsigned int diff_value;

		diff_value = *(it + 1) - *it;
		if (diff_value < shortest)
			shortest = diff_value;
	}
	return (shortest);
}

void	Span::printVector()
{
	std::sort(_tab.begin(), _tab.end());
	for (std::vector<unsigned int>::iterator it = _tab.begin(); it != _tab.end(); ++it)
			std::cout << *it << std::endl;
}

void Span::addNumbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	unsigned int distance = std::distance(begin, end);

	if (_tab.size() + distance > _N)
		throw std::length_error("Span is already full");
	_tab.insert(_tab.end(), begin, end);

}
