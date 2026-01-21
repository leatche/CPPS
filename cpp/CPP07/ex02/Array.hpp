/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:01:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/19 23:06:12 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

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
class Array
{
	private :

	T *_value;
	size_t	_size;

	public :
		Array() : _value(NULL), _size(0) {};
		Array(unsigned int n) : _value(NULL), _size(n) 
			{if (_size) _value = new T[n]();};
		Array(const Array &n) : _value(NULL), _size(0)
			{*this = n;};
		Array &operator=(const Array &other)
			{if (this == &other)
				return (*this);
			if (_size)
				delete[] _value;
			_value = NULL;
			_size = other._size;
			if (_size)
			{
				_value = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_value[i] = other._value[i];
			}
			return (*this);
		};

		T &operator[](size_t index)
		{
			if (index >= _size)
			throw std::out_of_range("Index out of bounds");
			return _value[index];
		}
		
		const T &operator[](size_t index) const {
			if (index >= _size)
				throw::std::out_of_range("Be careful : Index is higher or equal to the size");
			return (_value[index]);
		};
		~Array() {delete[] _value;};
		size_t size() const {return (_size);};
};
#endif
