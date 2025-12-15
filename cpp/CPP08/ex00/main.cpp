/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:29:13 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/11 16:50:05 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		::easyfind(v, 20);
		::easyfind(v, 5);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << "5" << std::endl;
	}
	
	

return 0;
}
