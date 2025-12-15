/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:58:48 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/04 11:32:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:

		Intern();
		~Intern();
		Intern(Intern const &n);
		Intern& operator=(Intern const &a);
		
		AForm* makeShrubbery(std::string const &target) const;
		AForm* makeRobotomy(std::string const&target) const;
		AForm* makePardon(std::string const&target) const;
		
		AForm *makeForm(std::string const &name, std::string const &target);
};

#endif
