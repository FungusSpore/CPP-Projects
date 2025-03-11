/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:55:26 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/10 00:46:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv){
	std::string	infile;
	std::string	outfile;
	std::string line;

	if (argc != 4){
		std::cerr << "Error: ./loser <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	infile = argv[1];
	std::ifstream	file1(infile.c_str());
	if (!file1.is_open()){
		std::cerr << "Error: file1 error" << std::endl;
		return (2);
	}

	outfile += ".replace";
	std::ofstream	file2(outfile.c_str());
	if(!file2.is_open()){
		std::cerr << "Error: file2 error" << std::endl;
		return (3);
	}

	while (std::getline(file1, line)){
		std::cout << line << std::endl;
	}
}
