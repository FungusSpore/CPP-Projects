/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:57:23 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/20 18:37:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char** argv){
	try{
		if (argc != 2 )
			std::cout << "Error: could not open file." << std::endl;
		std::ifstream infile(argv[1]);
		if (!infile.is_open())
			throw BitcoinExchange::FileCannotOpen("Error: could not open file");

		BitcoinExchange BitcoinExchange("cpp_09/data.csv");
		std::string line;

		while (std::getline(infile, line)){
			tm		key;
			float value = 0;
			
			std::memset(&key, 0, sizeof(tm));

			std::string key_str = line.substr(0, line.find("|"));
			line.erase(0, line.find(",") + 1);
			std::string value_str = line;

			if (!BitcoinExchange::date_format_checker(key_str) \
			&& !BitcoinExchange::date_parser(key_str, key))
				continue ;
			value = BitcoinExchange::value_parser(value_str);
			if (!BitcoinExchange::value_format_checker(value))
				continue ;

			std::cout << key_str << "=>" << value_str << 

		}
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
