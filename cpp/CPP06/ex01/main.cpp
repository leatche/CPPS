/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:07:02 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/03 18:38:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;
    data.value2 = 11;

    std::cout << "initial data's adress : " << &data << std::endl;

    std::cout << "initial data's value : " << data.value << std::endl;
    std::cout << "initial data's value2 : " << data.value2 << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "an adress to an int: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "an int to an adress: " << ptr << std::endl;
    return 0;
}
