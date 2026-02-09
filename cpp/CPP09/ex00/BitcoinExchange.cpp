/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:36:21 by tcherepoff        #+#    #+#             */
/*   Updated: 2026/02/09 14:06:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void Bitcoin::transfer_data_to_map()
{
	std::ifstream file("data.csv");
	if (!file)
		throw std::runtime_error("Error: could not open data.csv");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t date_size = line.find(',');
		std::string date = line.substr(0, date_size);
		double price = std::atof(line.substr(date_size + 1).c_str());
		_database[date] = price;
	}
	file.close();
}

void Bitcoin::compare_input_to_map(char *av)
{
	std::ifstream file(av);
	if (!file)
		throw std::runtime_error("Error: could not open your input");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t date_size = line.find('|');
		if (date_size == std::string::npos)
		{
			std::cerr << BRED << "Error: bad input => | is missing" << RESET << std::endl;
			continue;
		}
		std::string date = line.substr(0, date_size);
		trim(date);
		if (good_date_synthax(date) == false)
			continue;
		double price;
		std::string price_string = line.substr(date_size + 1);
		if (good_price_synthax(price_string, price) == false)
			continue;
		print_amount_bitcoin(price, date);
	}
	file.close();
}

bool Bitcoin::good_date_synthax(std::string date)
{
	if (date.length() >= 11 )
	{
		std::cerr << BRED << "Error: bad input => too long values" << RESET << std::endl;
		return (false);
	}


	size_t year_size = date.find('-');
	int y = std::atoi(date.substr(0, 4).c_str());
	if (year_size != 4)
	{
		std::cerr << BRED << "Error: bad input => wrong year : " << date << RESET << std::endl;
		return (false);
	}


	size_t month_size = date.find('-', year_size + 1);
	std::string month = date.substr(year_size + 1, month_size - (year_size + 1));
	int m = std::atoi(month.c_str());
	if (month_size == std::string::npos)
	{
		std::cerr << BRED << "Error: bad input => no day is given : " << date << RESET << std::endl;
		return (false);
	}
	if (m < 1 || m > 12)
	{
		std::cerr << BRED << "Error: bad input => this month doesn't exist : " << date << RESET << std::endl;
		return (false);
	}


	std::string day = date.substr(month_size + 1);
	int d = std::atoi(day.c_str());
	if (d < 1 || d > 31)
	{
		std::cerr << BRED << "Error: bad input => this day doesn't exist : " << date << RESET << std::endl;
		return (false);
	}

	
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
	return (std::cerr << BRED << "Error: bad input => this day doesn't exist : " << date << RESET << std::endl, false);

	if (m == 2 && (d > 29 || (d == 29 && y % 4 != 0)))
	return (std::cerr << BRED << "Error: bad input => this day doesn't exist : " << date << RESET << std::endl, false);

	return (true);
}

bool Bitcoin::good_price_synthax(std::string &s, double &price)
{
	char* end;
	price = std::strtod(s.c_str(), &end);
	if (*end != '\0')
	{
		std::cerr << BRED << "Error: bad input => invalid characters" << RESET << std::endl;
		return false;
	}
	if (price < 0.0)
	{
		std::cerr << BRED << "Error: not a positive number" << RESET << std::endl;
		return false;
	}
	if (price > 1000.0)
	{
		std::cerr << BRED << "Error: too large a number" << RESET << std::endl;
		return false;
	}
	return (true);
}

void	Bitcoin::print_amount_bitcoin(double &price, std::string &date)
{
	std::map<std::string, double>::iterator it = _database.lower_bound(date);
	if (it == _database.begin() && it->first != date)
	{
		std::cerr << BRED << "Error: no earlier date available" << RESET << std::endl;
		return;
	}
	else if (it == _database.end() || it->first != date)
	{
		--it;
		std::cout << "( New date of " << date << " ) : " << it->first << " => " << price << " = " << (it->second * price) << std::endl;
		return ;
	}
	else if (it->first != date)
	{
		--it;
		std::cout << "( New date of " << date << " ) : " << it->first << " => " << price << " = " << (it->second * price) << std::endl;
		return ;
	}
	else
		std::cout << it->first << " => " << price << " = " << (it->second * price) << std::endl;
}

void Bitcoin::trim(std::string &date)
{
	size_t start = 0;
	while (start < date.size() && std::isspace(date[start]))
		++start;
	size_t end = date.size();
	while (end > start && std::isspace(date[end - 1]))
		--end;
	date = date.substr(start, end - start);
}

Bitcoin::Bitcoin()
{
	
}

Bitcoin::Bitcoin(const Bitcoin &toCopy)
{
	*this = toCopy;
}

Bitcoin::~Bitcoin()
{
}

Bitcoin &Bitcoin::operator=(const Bitcoin &toCopy)
{
	_database = toCopy._database;
	return (*this);
}
