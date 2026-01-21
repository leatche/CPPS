/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:21 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/19 23:06:30 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::calculator_RPN(std::string c)
{
	int result;
	for (size_t i = 0; i < c.length(); i++)
	{
		if (std::isspace(c[i]))
			continue;
		else if (std::isdigit(c[i]))
		{
			if ((c[i] - 48) < 10)
				_stack.push(c[i] - 48);
			else
				throw::std::invalid_argument("Be careful : Number needs to be between 0 and 9");
		}
		else if (std::strchr("+-*/", c[i]))
		{
			if (_stack.size() > 1)
			{

				int right = _stack.top();
				_stack.pop();
				int left = _stack.top(); // left / right
				_stack.pop();



				if (c[i] == '/')
				{
					if (right == 0)
						throw::std::invalid_argument("Be careful : You try to divide by 0 :)");
					result = left / right;
				}
				else if (c[i] == '*')
					result = left * right;
				else if (c[i] == '+')
					result = left + right;
				else
					result = left - right;

				
				_stack.push(result);
			}
			else
				throw::std::invalid_argument("Be careful : Your espression is wrong, your operator try to be use with a single value or no value !");
		}
		else
			throw::std::invalid_argument("Be careful : There is a bad character !");
	}
	
	if (_stack.size() != 1)
		throw::std::invalid_argument("Be careful : Your espression is wrong, your final stack have more than 1 value. You perhaps forgot an operator ;) !");
	return (_stack.top());
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
