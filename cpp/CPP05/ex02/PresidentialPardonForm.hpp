/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:52:59 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/11/21 10:29:58 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
	
	public :
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &n);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &a);

		virtual void execute(Bureaucrat const &executor) const;

};

#endif
