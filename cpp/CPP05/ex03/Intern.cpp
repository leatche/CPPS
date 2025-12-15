/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:58:58 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/07 18:10:19 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &n)
{
	(void)n;
}

Intern& Intern::operator=(Intern const &a)
{
	(void)a;
	return (*this);
}

Intern::~Intern(void)
{
}
AForm* Intern::makeShrubbery(std::string const &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(std::string const &target) const{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(std::string const &target) const {
    return new PresidentialPardonForm(target);
}


AForm*	Intern::makeForm(std::string const &name, std::string const &target)
{
	std::cout << " Intern creates " << name << std::endl;

	typedef AForm* (Intern::*formType)(std::string const &target) const;

	std::string const names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	formType const methods[3] =
    {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            std::cout << "[Intern] Crafting a new form: " << name << std::endl;
            return (this->*methods[i])(target);
        }
    }
    throw std::invalid_argument("\033[1;31mUnknown form name `" + name + "`" + RESET);
}
