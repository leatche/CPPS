/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/02/09 14:13:51 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

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
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>

class RPN
{
	private :
		std::stack<int> _stack;
	public :
		RPN();
		~RPN();
		RPN(const RPN &toCopy);
		RPN &operator=(const RPN &toCopy);


		int calculator_RPN(std::string calcul);
};
#endif
