/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:04:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/20 10:00:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ########################################################################## //
// #                                 FORM                                   # //
// ########################################################################## //

Form::Form() : _name("Unknow"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "Form "<< _name << " arrived in order to be sign " << std::endl;
}
Form::~Form()
{
	std::cout << "Form "<< _name << " was put to the bin ... so sad :( " << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_exe) : _name(name), _signed(false), _grade_to_sign(grade_sign), _grade_to_execute(grade_exe)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException("You gave a higher grade than expected");
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException("You gave a lower grade than expected");
	std::cout << "Form "<< _name << " arrived in order to be sign" << std::endl;
}

Form::Form(const Form &n) : _grade_to_sign(150), _grade_to_execute(150)
{
	*this = n;
}
Form& Form::operator=(const Form &a)
{
	_signed = a._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Form &a)
{
	out << a.getName() << " form need a " << a.getGradeExe() << " to be execute and a " << a.getGradeSig() << "to be sign. Is it signed ? "  << a.getSigned();
	return out;
}


// ########################################################################## //
// #                              TOO-LOW                                   # //
// ########################################################################## //

const char *Form::GradeTooLowException::what() const throw(){
	return _content.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string content)
{
	_content = content;
}

Form::GradeTooLowException::GradeTooLowException()
{
	_content = "empty";
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

// Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &n)
// {
// 	*this = n;
// }

// Form::GradeTooLowException& Form::GradeTooLowException::operator=(const GradeTooLowException &a)
// {
// 	_content = a._content;
// 	return (*this);
// }

// ########################################################################## //
// #                              TOO-HIGH                                  # //
// ########################################################################## //

const char *Form::GradeTooHighException::what() const throw(){
	return _content.c_str();
}

Form::GradeTooHighException::GradeTooHighException(std::string content)
{
	_content = content;
}

Form::GradeTooHighException::GradeTooHighException()
{
	_content = "empty";
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

// Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &n)
// {
// 	*this = n;
// }

// Form::GradeTooHighException& Form::GradeTooHighException::operator=(const GradeTooHighException &a)
// {
// 	_content = a._content;
// 	return (*this);
// }

// ########################################################################## //
// #                              GETTER                                    # //
// ########################################################################## //



int Form::getGradeExe() const
{
	return (_grade_to_execute);
}

const std::string& Form::getName() const
{
	return (_name);
}

int Form::getGradeSig() const
{
	return (_grade_to_sign);
}

bool Form::getSigned() const
{
	return (_signed);
}


// ########################################################################## //
// #                              METHODES                                  # //
// ########################################################################## //

void Form::beSigned(Bureaucrat& a)
{
	if (a.getGrade() > _grade_to_sign)
		throw GradeTooLowException("his grade is too low compare to the needed one");
	_signed = true;
}
