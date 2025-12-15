/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:52:10 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 20:49:05 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Unknow", 72, 45)
{
	_target = "Unknow";
	std::cout << "RobotomyRequestForm create " << _target << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << " is erase" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	_target = target;
	std::cout << BORANGE << "RobotomyRequestForm create " << _target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &n) : AForm(n)
{
	*this = n;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
	_target = a._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::CheckExecutability(executor);
	std::cout << BGREEN << "🔔 driiiiinnnnngggggg 🔔" << RESET << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " Form has been robotomized" << std::endl;
	else
		std::cout << _target << " Form hasn't been robotomized" << std::endl;
}
