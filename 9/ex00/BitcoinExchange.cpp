/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:14:01 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/20 22:53:06 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <regex.h>
#include <cstdlib>

//********************************************************
// ORTHODOX FUNCTIONS
//********************************************************

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string data_path){
	std::string line;
	std::ifstream data(data_path.c_str());

	if (!data.is_open())
		throw FileCannotOpen("BitcoinExchange Database could not be accessed");

	std::getline(data, line); // remove title
	while (std::getline(data, line)){
		tm		key;
		float value = 0;
		
		std::memset(&key, 0, sizeof(tm));
		std::string key_str = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);
		std::string value_str = line;
		if (!(date_format_checker(key_str) && date_parser(key_str, key)))
			continue ;
		value = value_parser(value_str);
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

float		BitcoinExchange::exchangeRate(tm date){
	std::map<tm, float>::iterator it = this->database.begin();
	std::map<tm, float>::iterator prev_it;

	for (; it != this->database.end(); it++){
		tmComparitor<tm> cmp;
		if (cmp(date, it->first))
			break ;
		prev_it = it;
	}
	return (prev_it->second);
}

//********************************************************
// STATIC FUNCTIONS
//********************************************************

bool		BitcoinExchange::date_format_checker(std::string date_str){
	const char* dateFormat("^[0-9]{4}-[0-9]{2}-[0-9]{2}$");
	regex_t regex;

	if (regcomp(&regex, dateFormat, REG_EXTENDED | REG_NOSUB) != 0){
		std::cerr << "Error: Failed to compile regex\n";
		return false;
	}
	int ret = regexec(&regex,date_str.c_str(), 0, NULL, 0);
	regfree(&regex);
	if (ret != 0){
		std::cerr << "Error: bad input => " << date_str << std::endl;
		return false;
	}
	return true;
}

bool		BitcoinExchange::date_parser(std::string date_str, tm& date){
	std::string ori = date_str;
	std::string year = date_str.substr(0, date_str.find("-"));
	date_str.erase(0, date_str.find("-") + 1);
	std::string month = date_str.substr(0, date_str.find("-"));
	date_str.erase(0, date_str.find("-") + 1);
	std::string day = date_str;
	
	date.tm_year = std::atoi(year.c_str()) - 1900;
	date.tm_mon = std::atoi(month.c_str()) - 1;
	date.tm_mday = std::atoi(day.c_str());
	tm temp = date;
	mktime(&date);
	if (date.tm_year != temp.tm_year 
		|| date.tm_mon != temp.tm_mon 
		|| date.tm_mday != temp.tm_mday){
		std::cerr << "Error: bad input => " << ori << std::endl;
		return false;
	}
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

//********************************************************
// EXCEPTION FUNCTIONS
//********************************************************

BitcoinExchange::FileCannotOpen::FileCannotOpen(const std::string msg):msg(msg){}

const char* BitcoinExchange::FileCannotOpen::what() const throw(){
	return (msg.c_str());
}

BitcoinExchange::FileCannotOpen::~FileCannotOpen() throw(){}
