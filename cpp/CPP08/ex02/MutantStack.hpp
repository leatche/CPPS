/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:10:52 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/26 11:32:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


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
#include <stack>
#include <limits>
#include <stdexcept>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterators;
		iterators begin()
		{
			return (this->c.begin());
		}
		iterators end()
		{
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const 
		{ 
			return (this->c.begin());
		}
		const_iterator end() const
		{ 
			return (this->c.end()); 
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin()
		{ 
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{ 
			return (this->c.rend()); 
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const
		{ 
			return (this->c.rbegin());
		}
		const_reverse_iterator rend() const
		{ 
			return (this->c.rend()); 
		}
};

#endif
