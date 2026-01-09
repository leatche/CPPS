/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:30 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/03 18:44:40 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <stdint.h>
# include <ctime>
# include <limits>
# include <cctype>

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

class Base
{
	public :
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
