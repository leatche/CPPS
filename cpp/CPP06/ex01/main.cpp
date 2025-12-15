/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:07:02 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/12/11 15:14:03 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    std::cout << "initial data's value : " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "an adress to an int: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "an int to an adress: " << ptr << std::endl;
    return 0;
}
