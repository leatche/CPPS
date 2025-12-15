/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:07:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/19 15:34:45 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bobby("Bobby", 15050);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": the grade must be initialized between 1 and 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << ": the grade must be initialized between 1 and 150" << std::endl;
	}


	try
	{
		Bureaucrat fobby("Fobby", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": the grade must be initialized between 1 and 150" << std::endl;
	}


	try
	{
		Bureaucrat gobby("Gobby", -1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": the grade must be initialized between 1 and 150" << std::endl;
	}

	
	try
	{
		std::cout << std::endl;
		Bureaucrat dobby("Dobby", 150);
		Bureaucrat hobby("Hobby", 15);

		std::cout << std::endl;
		std::cout << dobby << std::endl;
		std::cout << hobby << std::endl;
		
		std::cout << std::endl;
		hobby.DownGrade();
		hobby.DownGrade();
		hobby.DownGrade();
		hobby.DownGrade();

		std::cout << hobby << std::endl;

		hobby.UpGrade();
		hobby.UpGrade();
		hobby.UpGrade();
		hobby.UpGrade();

		std::cout << hobby << std::endl;

		std::cout << std::endl;
		dobby.DownGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
