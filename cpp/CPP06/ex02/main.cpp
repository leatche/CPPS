/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:07:02 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/01/03 18:48:55 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    srand(time(NULL));

    Base *a = generate();
    Base *b = generate();
    Base *c = generate();
    Base *d = generate();
    Base *e = generate();
    Base *f = generate();
    Base *g = generate();
    Base *h = generate();

    std::cout << std::endl;

    identify(a);
    identify(*a);
    identify(b);
    identify(*b);
    identify(c);
    identify(*c);
    identify(d);
    identify(*d);
    identify(e);
    identify(*e);
    identify(f);
    identify(*f);
    identify(g);
    identify(*g);
    identify(h);
    identify(*h);

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
}
