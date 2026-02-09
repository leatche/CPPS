/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/02/09 13:49:55 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

#include <iostream>
#include <cstddef>
#include <stack>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

class Bitcoin
{
	private :
		std::map<std::string, double> _database;
	public :
		Bitcoin();
		~Bitcoin();
		Bitcoin(const Bitcoin &toCopy);
		Bitcoin &operator=(const Bitcoin &toCopy);
		void transfer_data_to_map();
		void compare_input_to_map(char *av);

		bool good_date_synthax(std::string date);
		bool good_price_synthax(std::string &s, double &price);

		void print_amount_bitcoin(double &price, std::string &date);
		void trim(std::string &date);
};
#endif
