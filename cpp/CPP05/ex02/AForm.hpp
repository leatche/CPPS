/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:05:20 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/19 18:09:11 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool			_signed;
		const int		_grade_to_sign;
		const int		_grade_to_execute;

	protected :
	void CheckExecutability(Bureaucrat const &executor) const;

	public:
	AForm();
	~AForm();
	AForm(std::string name, int grade_sign, int grade_exe);
	AForm(const AForm &n);
	AForm& operator=(const AForm &a);

	int getGradeExe() const;
	const std::string& getName() const;
	int getGradeSig() const;
	bool getSigned() const;


	void beSigned(Bureaucrat& a);
	virtual void execute(Bureaucrat const &executor) const = 0;


	class GradeTooLowException : public std::exception
	{
		private :
		std::string _content;

		public :
		virtual const char *what() const throw();
		GradeTooLowException(std::string content);
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		// GradeTooLowException(const GradeTooLowException &n);
		// GradeTooLowException& operator=(const GradeTooLowException &a);
	};
	
	class GradeTooHighException : public std::exception
	{
		private :
		std::string _content;

		public :
		virtual const char *what() const throw();
		GradeTooHighException(std::string content);
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		// GradeTooHighException(const GradeTooHighException &n);
		// GradeTooHighException& operator=(const GradeTooHighException &a);
	};

	class NotSignedException : public std::exception
	{
		private:
			std::string _content;
		
		public:
			NotSignedException(std::string msg);
			virtual ~NotSignedException() throw ();
			virtual const char *what() const throw();
		};

	class ClassicError : public std::exception
	{
		private:
			std::string _content;
		
		public:
			ClassicError(std::string msg);
			virtual ~ClassicError() throw ();
			virtual const char *what() const throw();
	};
};

#endif
