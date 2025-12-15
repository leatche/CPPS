/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:49:51 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 20:46:29 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknow", 145, 137)
{
	_target = "Unknow";
	std::cout << "ShrubberyCreationForm create " << _target << "_shrubbery in the working directory " << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _target << "_shrubbery is erase from the working directory " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	_target = target;
	std::cout << BORANGE << "ShrubberyCreationForm create " << _target << "_shrubbery in the working directory " << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &n) : AForm(n)
{
	*this = n;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	_target = a._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::CheckExecutability(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
		throw GradeTooLowException("Could not open shrubbery file");
	
file << "                     ★" << std::endl;
file << "                     /\\\\" << std::endl;
file << "                    /  \\\\" << std::endl;
file << "                   /++++\\\\" << std::endl;
file << "                  /  ()  \\\\" << std::endl;
file << "                 /++++++++\\\\" << std::endl;
file << "                /    ()    \\\\" << std::endl;
file << "               /++++++++++++\\\\" << std::endl;
file << "              /      ()      \\\\" << std::endl;
file << "             /++++++++++++++++\\\\" << std::endl;
file << "            /        ()        \\\\" << std::endl;
file << "           /++++++++++++++++++++\\\\" << std::endl;
file << "          /          ()          \\\\" << std::endl;
file << "         /++++++++++++++++++++++++\\\\" << std::endl;
file << "        /            ()            \\\\" << std::endl;
file << "       /++++++++++++++++++++++++++++\\\\" << std::endl;
file << "      /              ()              \\\\" << std::endl;
file << "     /++++++++++++++++++++++++++++++++\\\\" << std::endl;
file << "                    |||||||" << std::endl;
file << "                    |||||||" << std::endl;

}
