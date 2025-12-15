/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:01:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/02 12:06:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>


template <typename T>
class Array
{
	private :

	T *_value;
	size_t	_size;

	public :
		Array() : _value(NULL), _size(0) {};
		Array(unsigned int n) : _size(n) {_value = new T[n]();};
		Array(const Array &n) : _value(NULL), _size(0) {*this = n;};
		Array &operator=(const Array &other) {
			if (_size)
				delete[] _value;
			_size = other._size;
			if (_size)
			{
				_value = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_value[i] = other._value[i];
			}
			return (*this);
		};
		
		T &operator[](size_t index) {
			if (index >= _size)
				throw::std::out_of_range("Index higher or equal to the size");
			return (_value[index]);
		};
		~Array() {delete[] _value;};
		size_t size() {return (_size);};
};
#endif
