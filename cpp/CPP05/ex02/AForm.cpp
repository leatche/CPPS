/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:04:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/19 18:17:53 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// ########################################################################## //
// #                                 AFORM                                  # //
// ########################################################################## //

AForm::AForm() : _name("Unknow"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "AForm "<< _name << " arrived in order to be sign " << std::endl;
}
AForm::~AForm()
{
	std::cout << "AForm "<< _name << " was put to the bin ... so sad :( " << std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_exe) : _name(name), _signed(false), _grade_to_sign(grade_sign), _grade_to_execute(grade_exe)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw GradeTooHighException("The grade is higher than expected");
	else if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw GradeTooLowException("The grade is lower than expected");
	std::cout << "AForm "<< _name << " arrived in order to be sign" << std::endl;
}

AForm::AForm(const AForm &n) : _grade_to_sign(150), _grade_to_execute(150)
{
	*this = n;
}
AForm& AForm::operator=(const AForm &a)
{
	_signed = a._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const AForm &a)
{
	out << a.getName() << " Aform need a " << a.getGradeExe() << " to be execute and a " << a.getGradeSig() << "to be sign. Is it signed ? "  << a.getSigned();
	return out;
}


// ########################################################################## //
// #                              TOO-LOW                                   # //
// ########################################################################## //

const char *AForm::GradeTooLowException::what() const throw(){
	return _content.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string content)
{
	_content = content;
}

AForm::GradeTooLowException::GradeTooLowException()
{
	_content = "empty";
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

// AForm::GradeTooLowException::GradeTooLowException(const GradeTooLowException &n)
// {
// 	*this = n;
// }

// AForm::GradeTooLowException& AForm::GradeTooLowException::operator=(const GradeTooLowException &a)
// {
// 	_content = a._content;
// 	return (*this);
// }

// ########################################################################## //
// #                              TOO-HIGH                                  #  _grade//
// ########################################################################## //

const char *AForm::GradeTooHighException::what() const throw(){
	return _content.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(std::string content)
{
	_content = content;
}

AForm::GradeTooHighException::GradeTooHighException()
{
	_content = "empty";
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

// AForm::GradeTooHighException::GradeTooHighException(const GradeTooHighException &n)
// {
// 	*this = n;
// }

// AForm::GradeTooHighException& AForm::GradeTooHighException::operator=(const GradeTooHighException &a)
// {
// 	_content = a._content;
// 	return (*this);
// }

// ########################################################################## //
// #                              SIGNED                                    # //
// ########################################################################## //

AForm::NotSignedException::NotSignedException(std::string msg) : _content(msg)
{

}
AForm::NotSignedException::~NotSignedException() throw ()
{

}
const char *AForm::NotSignedException::what() const throw()
{
	return _content.c_str();
}

// ########################################################################## //
// #                              ERROR                                    # //
// ########################################################################## //

AForm::ClassicError::ClassicError(std::string msg) : _content(msg)
{

}
AForm::ClassicError::~ClassicError() throw ()
{

}
const char *AForm::ClassicError::what() const throw()
{
	return _content.c_str();
}

// ########################################################################## //
// #                              GETTER                                    # //
// ########################################################################## //

int AForm::getGradeExe() const
{
	return (_grade_to_execute);
}

const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getGradeSig() const
{
	return (_grade_to_sign);
}

bool AForm::getSigned() const
{
	return (_signed);
}


// ########################################################################## //
// #                              METHODES                                  # //
// ########################################################################## //

void AForm::beSigned(Bureaucrat& a)
{
	if (a.getGrade() > _grade_to_sign)
		throw GradeTooLowException("his grade is too low compare to the needed one");
	_signed = true;
}

void AForm::CheckExecutability(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _grade_to_execute)
		throw (AForm::ClassicError(executor.getName() + " cannot execute the " + _name + " form because his grade is too low"));
	if (!_signed)
		throw (AForm::NotSignedException(_name + " isn't signed !"));
}
