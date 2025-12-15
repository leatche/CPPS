/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:39:34 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/09 14:20:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t a;
	a = reinterpret_cast<uintptr_t>(ptr);
	return (a);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* b;
	b = reinterpret_cast<Data*>(raw);
	return (b);
}
