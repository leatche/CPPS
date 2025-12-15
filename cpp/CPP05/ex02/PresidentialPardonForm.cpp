/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:53:04 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 20:48:51 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Unknow", 25, 5)
{
	_target = "Unknow";
	std::cout << "PresidentialPardonForm create " << _target << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << _target << " is erase" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	_target = target;
	std::cout << BORANGE << "PresidentialPardonForm create " << _target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &n) : AForm(n)
{
	*this = n;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	_target = a._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::CheckExecutability(executor);
	std::cout << BGREEN << _target <<" has been pardoned by 👑 Zaphod Beeblebrox 👑." << RESET << std::endl;
}
