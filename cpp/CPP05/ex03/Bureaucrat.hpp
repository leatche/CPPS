/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:24:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 11:39:09 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET		"\033[0m"
#define BRED		"\033[1;31m"
#define BGREEN		"\033[1;32m"
#define BYELLOW		"\033[1;33m"
#define BBLUE		"\033[1;34m"
#define BMAGENTA	"\033[1;35m"
#define BCYAN		"\033[1;36m"
#define BORANGE		"\033[1;38;5;208m"
#define BPINK		"\033[1;38;5;213m"
#define BPURPLE		"\033[1;38;5;57m"
#define BTEAL		"\033[1;38;5;30m"

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &n);
		Bureaucrat& operator=(const Bureaucrat &a);

		int getGrade() const;
		const std::string& getName() const;
		void DownGrade();
		void UpGrade();
		void signForm(AForm& a);

		void executeForm(AForm const & form) const;

		class GradeTooLowException : std::exception
		{
			private :
			std::string _content;

			public :
			virtual const char *what() const throw();
			GradeTooLowException(std::string content);
			GradeTooLowException();
			virtual ~GradeTooLowException() throw();
			GradeTooLowException(const GradeTooLowException &n);
			GradeTooLowException& operator=(const GradeTooLowException &a);
		};
		
		class GradeTooHighException : std::exception
		{
			private :
			std::string _content;

			public :
			virtual const char *what() const throw();
			GradeTooHighException(std::string content);
			GradeTooHighException();
			virtual ~GradeTooHighException() throw();
			GradeTooHighException(const GradeTooHighException &n);
			GradeTooHighException& operator=(const GradeTooHighException &a);
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a);

#endif
