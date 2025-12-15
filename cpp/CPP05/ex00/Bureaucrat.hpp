/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:24:12 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/20 09:58:49 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>

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

		class GradeTooLowException : std::exception
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
		
		class GradeTooHighException : std::exception
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &a);

#endif
