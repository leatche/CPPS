/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:30 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/03 18:33:12 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <stdint.h>
# include <ctime>
# include <limits>
# include <cctype>

struct Data
{
	int value;
	int value2;
};

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
