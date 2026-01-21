/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:17:34 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/20 18:52:08 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ########################################################################## //
// #                              PARSING                                   # //
// ########################################################################## //


size_t Ford_Johnson::pars_av(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				throw::std::invalid_argument("Be careful : You are only allowed to write positive integers, no space or other character is allowed !");
		}
		_input.push_back(std::atoi(av[i]));
	}

	_deque.assign(_input.begin(), _input.end());
	_vector.assign(_input.begin(), _input.end());

	std::cout << "Before : ";
	for (size_t i = 0; i < _input.size(); ++i)
		std::cout << _input[i] << " ";
	std::cout << std::endl;

	return (_input.size());
}



// ########################################################################## //
// #                              DEQUE                                     # //
// ########################################################################## //



double Ford_Johnson::deque_algo()
{
	long long start = get_time_us();
	_pairs.clear();

	if (_deque.size() <= 1)
		return 0;
	
	bool odd = (_deque.size() % 2 != 0);
	int odd_value = 0;
	if (odd == true)
	{
		odd_value = _deque.back();
		_deque.pop_back();
	}

	do_pairs();
	insert_bigs();
	insert_smalls();

	if (odd)
		insert_odd(odd_value);

	long long end = get_time_us();
	return (end - start);
}

void Ford_Johnson::do_pairs()
{
	for (size_t i = 0; i + 1 < _deque.size(); i += 2)
	{
		int a = _deque[i];
		int b = _deque[i + 1];
		
		if (a < b)
			_pairs.push_back(std::make_pair(a, b));
		else
			_pairs.push_back(std::make_pair(b, a));
	}
}

void Ford_Johnson::insert_bigs()
{
	std::deque<int> bigs;
	for (size_t i = 0; i < _pairs.size(); ++i)
		bigs.push_back(_pairs[i].second);
	
	Ford_Johnson tmp;
	tmp._deque = bigs;
	tmp.deque_algo();

	_deque = tmp._deque;
}

void Ford_Johnson::insert_smalls()
{
	std::vector<size_t> _jacob = build_jacobsthal(_pairs.size());

	size_t prev = 0;
	for (size_t k = 0; k < _jacob.size(); ++k)
	{
		size_t current = _jacob[k];
		
		for (size_t i = current; i > prev; --i)
		{
			int value = _pairs[i - 1].first;
			std::deque<int>::iterator position = std::lower_bound(_deque.begin(), _deque.end(), value);
			_deque.insert(position, value);
		}
		prev = current;
	}
}

void Ford_Johnson::insert_odd(int odd_value)
{
	std::deque<int>::iterator position = std::lower_bound(_deque.begin(), _deque.end(), odd_value);
	_deque.insert(position, odd_value);
}




// ########################################################################## //
// #                              VECTOR                                    # //
// ########################################################################## //

double Ford_Johnson::vector_algo()
{
	long long start = get_time_us();
	_pair.clear();

	if (_vector.size() <= 1)
		return 0;

	bool odd = (_vector.size() % 2 != 0);
	int odd_value = 0;
	if (odd)
	{
		odd_value = _vector.back();
		_vector.pop_back();
	}

	do_pair();
	insert_big();
	insert_small();
	if (odd)
		insert_oddd(odd_value);

	long long end = get_time_us();
	return (end - start);

}


void Ford_Johnson::do_pair()
{
	for (size_t i = 0; i + 1 < _vector.size(); i += 2)
	{
		int a = _vector[i];
		int b = _vector[i + 1];

		if (a < b)
			_pair.push_back(std::make_pair(a, b));
		else
			_pair.push_back(std::make_pair(b, a));
	}
}

void Ford_Johnson::insert_big()
{
	std::vector<int> bigs;
	for (size_t i = 0; i < _pair.size(); ++i)
		bigs.push_back(_pair[i].second);

	Ford_Johnson tmp;
	tmp._vector = bigs;
	tmp.vector_algo();

	_vector = tmp._vector;
}


void Ford_Johnson::insert_small()
{
	std::vector<size_t> jacob = build_jacobsthal(_pair.size());

	size_t prev = 0;
	for (size_t k = 0; k < jacob.size(); ++k)
	{
		size_t current = jacob[k];

		for (size_t i = current; i > prev; --i)
		{
			int value = _pair[i - 1].first;
			std::vector<int>::iterator position = std::lower_bound(_vector.begin(), _vector.end(), value);
			_vector.insert(position, value);
		}
		prev = current;
	}
}


void Ford_Johnson::insert_oddd(int odd_value)
{
	std::vector<int>::iterator position = std::lower_bound(_vector.begin(), _vector.end(), odd_value);
	_vector.insert(position, odd_value);
}
// ########################################################################## //
// #                              CANONIQUE                                 # //
// ########################################################################## //


Ford_Johnson::Ford_Johnson(Ford_Johnson &toCopy)
{
	*this = toCopy;
}

Ford_Johnson &Ford_Johnson::operator=(Ford_Johnson &toCopy)
{
	_vector = toCopy._vector;
	_deque = toCopy._deque;
	return (*this);
}

Ford_Johnson::Ford_Johnson()
{
}

Ford_Johnson::~Ford_Johnson()
{
}



// ########################################################################## //
// #                              HELP FUNCTION                             # //
// ########################################################################## //


std::vector<size_t> Ford_Johnson::build_jacobsthal(size_t size)
{
	std::vector<size_t> jacob;

	if (size == 0)
		return jacob;

	size_t j0 = 0;
	size_t j1 = 1;

	while (j1 < size)
	{
		jacob.push_back(j1);

		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	jacob.push_back(size);
	return (jacob);
}

long long Ford_Johnson::get_time_us()
{
	timeval tv;
	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000000LL + tv.tv_usec);
}

void Ford_Johnson::print_deque()
{
	std::cout << "After : ";
	for (size_t i = 0; i < _deque.size(); ++i)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;
}
