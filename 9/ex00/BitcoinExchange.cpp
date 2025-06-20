/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:14:01 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/20 18:58:10 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex>

//********************************************************
// ORTHODOX FUNCTIONS
//********************************************************

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string data_path){
	std::string line;
	std::ifstream data(data_path);

	if (!data.is_open())
		throw FileCannotOpen("BitcoinExchange Database could not be accessed");
	while (std::getline(data, line)){
		tm		key;
		float value = 0;
		
		std::memset(&key, 0, sizeof(tm));
		std::string key_str = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);
		std::string value_str = line;
		if (!date_format_checker(key_str) && !date_parser(key_str, key))
			continue ;
		value = value_parser(value_str);
		if (!value_format_checker(value))
			continue ;

		this->database[key] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):database(other.database){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other){
		this->database = other.database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

//********************************************************
// STATIC FUNCTIONS
//********************************************************

// maybe need another checker for whether is has the proper fomatting or not
bool		BitcoinExchange::date_format_checker(std::string date_str){
	std::regex dateFormat("^\\d{4}-\\d{2}-\\d{2}$");
	if (!std::regex_match(date_str, dateFormat)){
		std::cerr << "Error: bad input " << date_str << std::endl;
		return false;
	}
	return true;
}

bool		BitcoinExchange::date_parser(std::string date_str, tm& date){
	std::string year = date_str.substr(0, date_str.find("-"));
	date_str.erase(0, date_str.find("-") + 1);
	std::string month = date_str.substr(0, date_str.find("-"));
	date_str.erase(0, date_str.find("-") + 1);
	std::string day = date_str;
	date.tm_year = std::stoi(year) - 1900;
	date.tm_mon = std::stoi(month) - 1;
	date.tm_mday = std::stoi(day);
	tm temp = date;
	mktime(&date);
	if (date.tm_year != temp.tm_year || date.tm_mon != temp.tm_mon || date.tm_mday != temp.tm_mday)
		return false;
	return true;
}

float		BitcoinExchange::value_parser(std::string value_str){
	return (atof(value_str.c_str()));
}

bool		BitcoinExchange::value_format_checker(float value){
	if (value < 0){
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000){
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

float	exchangeRate(tm date){


}

//********************************************************
// EXCEPTION FUNCTIONS
//********************************************************

BitcoinExchange::FileCannotOpen::FileCannotOpen(const std::string msg):msg(msg){}

const char* BitcoinExchange::FileCannotOpen::what() const throw(){
	return (msg.c_str());
}

BitcoinExchange::FileCannotOpen::~FileCannotOpen() throw(){}
