/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:01:24 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/02/09 14:27:31 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <sys/time.h>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>

class Ford_Johnson
{
	private :
		std::vector<int> _input;
		std::vector<int> _vector;
		std::deque<int> _deque;

		std::vector< std::pair<int, int> > _pair;
		std::deque< std::pair<int, int> > _pairs;

		double _time_deque;
		double _time_vector;
		
	public :
		Ford_Johnson();
		~Ford_Johnson();
		Ford_Johnson(Ford_Johnson &toCopy);
		Ford_Johnson &operator=(Ford_Johnson &toCopy);

		size_t pars_av(int ac, char **av);

		double deque_algo();
		void do_pairs();
		void insert_bigs();
		void insert_smalls();
		void insert_odd(int old_value);

		double vector_algo();
		void do_pair();
		void insert_big();
		void insert_small();
		void insert_oddd(int odd_value);

		void print_deque();
		void print_vector();
		long long get_time_us();
		std::vector<size_t> build_jacobsthal(size_t size);
};

#endif
