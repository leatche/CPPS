/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:05:20 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/20 11:42:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool			_signed;
		const int		_grade_to_sign;
		const int		_grade_to_execute;

	public:
	Form();
	~Form();
	Form(std::string name, int grade_sign, int grade_exe);
	Form(const Form &n);
	Form& operator=(const Form &a);

	int getGradeExe() const;
	const std::string& getName() const;
	int getGradeSig() const;
	bool getSigned() const;


	void beSigned(Bureaucrat& a);


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
};

#endif
