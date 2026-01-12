/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:21 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/10 13:21:22 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::calculator_RPN(std::string c)
{
	for (int i = 0; i < c.length(); i++)
	{
		if (std::isspace(c[i]))
			continue;
		else if (std::isdigit(c[i]) && ((c[i] - 48) < 10))
			_stack.push(c[i] - 48);
		else if 

	}
}


RPN::RPN(RPN &toCopy)
{
	*this = toCopy;
}

RPN &RPN::operator=(RPN &toCopy)
{
	_stack = toCopy._stack;
	return (*this);
}

RPN::RPN()
{
}

RPN::~RPN()
{
}
