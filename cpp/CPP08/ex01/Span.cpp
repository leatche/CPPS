/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:01:45 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/04 17:30:52 by tcherepoff       ###   ########.fr       */
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
	if (_currentN >= _N)
		throw std::length_error("Span is already full");
	_tab.push_back(add);
	_currentN++;
}

unsigned int Span::longestSpan()
{
	if (_tab.empty() || _tab.size() < 2)
		std::out_of_range("you can't find the longest span. There isn't enough number store");
	
	std::sort(_tab.begin(), _tab.end());
	return (*(_tab.end() - 1) - *(_tab.begin()));
}

unsigned int Span::shortestSpan()
{
	if (_tab.empty() || _tab.size() < 2)
		std::out_of_range("you can't find the shortest span. There isn't enough number store");
	
	std::sort(_tab.begin(), _tab.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();

	for (std::vector<unsigned int>::iterator it = _tab.begin(); it + 1 !=  _tab.end(); ++it)
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

void Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	unsigned int distance = std::distance(begin, end);

	if (_tab.size() + distance > _N)
		throw std::length_error("Span is already full");
	_tab.insert(_tab.end(), begin, end);

}
