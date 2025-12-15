/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:49:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/22 12:02:51 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ########################################################################## //
// #                              BUREAUCRAT                                # //
// ########################################################################## //

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) 
{
	std::cout << "A new Bureaucrat "<< _name << " arrived in the office " << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat "<< _name << " go back home " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException("You gave a higher grade than expected");
	else if (_grade > 150)
		throw GradeTooLowException("You gave a lower grade than expected");
	std::cout << "A new Bureaucrat "<< _name << " arrived in the office"  << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &n)
{
	*this = n;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a)
{
	_grade = a.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade();
	return out;
}

// ########################################################################## //
// #                              TOO-LOW                                   # //
// ########################################################################## //

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return _content.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string content)
{
	_content = content;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	_content = "empty";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &n)
{
	*this = n;
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &a)
{
	_content = a._content;
	return (*this);
}

// ########################################################################## //
// #                              TOO-HIGH                                  # //
// ########################################################################## //

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return _content.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string content)
{
	_content = content;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	_content = "empty";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &n)
{
	*this = n;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &a)
{
	_content = a._content;
	return (*this);
}

// ########################################################################## //
// #                              METHODES                                  # //
// ########################################################################## //


int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::DownGrade()
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException("You can't decrement the bureaucrat’s grade, he's already at the lower grade (150)");
	_grade += 1;
}

void	Bureaucrat::UpGrade()
{
	if ((_grade - 1) < 1)
		throw GradeTooHighException("You can't increment the bureaucrat’s grade, he's already at the higher grade (1)");
	_grade -= 1;
}

void Bureaucrat::signForm(AForm& a)
{
	try
	{
		a.beSigned(*this);
		std::cout << _name << " signed " << a.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << a.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
