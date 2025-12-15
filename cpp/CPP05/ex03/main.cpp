/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:07:05 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/07 18:09:43 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern NewIntern;
	Bureaucrat aobby("Aobby", 15);
	
	AForm *f1 = NewIntern.makeForm("shrubbery creation", "HIHI");
	aobby.signForm(*f1);
	aobby.executeForm(*f1);
	AForm *f2 = NewIntern.makeForm("robotomy request", "mimi");
	aobby.signForm(*f2);
	aobby.executeForm(*f2);
	NewIntern.makeForm("presidential pardon", "riri");
	try {
		NewIntern.makeForm("nothing", "titi");
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
	}
}

