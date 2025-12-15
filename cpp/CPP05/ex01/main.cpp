/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:07:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/20 08:48:33 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat hobby("Hobby", 15);

	std::cout << std::endl;
	std::cout << hobby << std::endl;
	hobby.DownGrade();
	hobby.UpGrade();
	
	std::cout << std::endl;
	Form one("one", 3, 4);
	Form two("two", 15, 15);
	Form three("three", 120, 120);
	
	std::cout << std::endl;
	hobby.signForm(three);
	hobby.signForm(two);
	hobby.signForm(one);
}
