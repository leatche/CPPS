/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:52:25 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 10:30:02 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
#define ROBOTONY_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private :
		std::string		_target;
	
	public :
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &n);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &a);

		virtual void execute(Bureaucrat const &executor) const;

};

#endif
