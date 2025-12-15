/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:07:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/22 12:05:29 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bobby("Bobby", 150);

		std::cout << std::endl;
		RobotomyRequestForm a("first document");
		a.execute(bobby);
	}
	catch(AForm::ClassicError &e)
	{
		std::cout << BCYAN << e.what() << ": the grade must be higher than 72 and 45" << RESET << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat cobby("Cobby", 150);

		std::cout << std::endl;
		ShrubberyCreationForm b("second document");

		b.execute(cobby);
	}
	catch(AForm::ClassicError &e)
	{
		std::cout << BCYAN << e.what() << ": the grade must be higher than 145 and 137" << RESET << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat dobby("Dobby", 150);

		std::cout << std::endl;
		PresidentialPardonForm c("third document");

		std::cout << std::endl;
		c.execute(dobby);
	}
	catch(AForm::ClassicError &e)
	{
		std::cout << BCYAN << e.what() << ": the grade must be higher than 25 and 5" << RESET << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat aobby("Aobby", 15);

		std::cout << std::endl;
		RobotomyRequestForm d("fourth document");
		aobby.signForm(d);
		d.execute(aobby);

		std::cout << std::endl;
		Bureaucrat fobby("Fobby", 4);

		std::cout << std::endl;
		ShrubberyCreationForm e("fifth document");
		fobby.signForm(e);
		e.execute(fobby);

		std::cout << std::endl;
		Bureaucrat gobby("Gobby", 4);

		std::cout << std::endl;
		PresidentialPardonForm f("sixth document");
		gobby.signForm(f);
		f.execute(gobby);

		std::cout << std::endl;
		Bureaucrat hobby("Hobby", 4);

		std::cout << std::endl;
		PresidentialPardonForm h("seventh document");
		hobby.executeForm(h); // h.execute(hobby) c'est un équivalent demandé par le sujet
	}
	catch(AForm::NotSignedException &e)
	{
		std::cout << BCYAN << e.what() << RESET << std::endl;
	}
}
