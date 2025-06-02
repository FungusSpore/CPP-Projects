#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
// #include <cstdint>
#include <limits>
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

// toChar will treat all float and double as invalid
// it will also treat all non-printable as invalid as well

// toInt will treat values from float and double greater or lesser than intmax/min to be invalid

// toFloat and toDouble will take any input

// if nan inf only float and double can display

std::string detect(std::string value){
	const std::string special_litterals[6] = {"nan", "inf", "-inf", "nanf", "inff", "-inff"};

	if (value.length() == 1 && !std::isdigit(value[0]))
		return ("char");
	if (value[value.length() - 1] == 'f')
		return ("float");
	if (value.find('.'))
		return ("double");
	for (int i = 0; i < 6; i++){
		if (i < 3 && value == special_litterals[i])
			return ("double");
		if (value == special_litterals[i])
			return ("float");
	}
	return ("int");
}

bool	is_valid(std::string value){
	const std::string special_litterals[6] = {"nan", "inf", "-inf", "nanf", "inff", "-inff"};

	for (int i = 0; i < 6; i++){
		if (value == special_litterals[i])
			return (true);
	}
	if (value.length() == 1)
		return (true);

	for (int i = 0; i < static_cast<int>(value.length()); i++){
		if (!std::isdigit(value[i]) && value[i] != '.'){
			if (i == static_cast<int>(value.length()) - 1 && value[i] == 'f')
				break ;
			return (false);
		}
	}
	return (true);
}

template <typename T>
void	printConverts(T value){
	std::cout << value << std::endl;
	std::cout << static_cast<int>(value) << std::endl;

	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: Impossible" << std::endl;
	else if (std::isprint(static_cast<int>(value)))
		std::cout << "char: " << static_cast<unsigned char>(value) << std::endl;
	else
		std::cout << "char: Non displable" << std::endl;

	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	std::cout.precision(std::numeric_limits<float>::digits10);
	std::cout << "float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;

	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << "double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void	toChar(std::string value){
	char	c = static_cast<char>(value[0]);

	printConverts<char>(c);
}

void	toInt(std::string value){
	int		number = std::atoi(value.c_str());

	printConverts<int>(number);
}

void	toFloat(std::string value){
	const std::string special_doubles[3] = {"nan", "inf", "-inf"};
	const std::string special_floats[3] = {"nanf", "inff", "-inff"};

	bool	possible = true;
	float number;
	int		i;

	for (i = 0; i < 3; i++){
		if (value == special_floats[i])
			possible = false;
	}
	if (possible)
		number = std::atof(value.c_str());

	if (!possible){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << std::endl;
		std::cout << "double: "<< special_doubles[i] << std::endl;
		return ;
	}
	printConverts<float>(number);
}

void	toDouble(std::string value){
	const std::string special_doubles[3] = {"nan", "inf", "-inf"};
	const std::string special_floats[3] = {"nanf", "inff", "-inff"};

	bool	possible = true;
	double number;
	int		i;

	for (i = 0; i < 3; i++){
		if (value == special_doubles[i])
			possible = false;
	}
	if (possible)
		number = std::atof(value.c_str());

	if (!possible){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << special_floats[i] << std::endl;
		std::cout << "double: "<< value << std::endl;
		return ;
	}
	printConverts(number);
}

void ScalarConverter::convert(std::string value){
	typedef void (*FuncPtr)(const std::string);

	const FuncPtr	typeHandlers[4] = {toChar, toInt, toFloat, toDouble};
	const std::string dataTypes[4] = {"char", "int", "float", "double"};
	std::string type;
	// error checking
	if (!is_valid(value)){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	// detect
	type = detect(value);
	for (int i = 0; i < 4; i++){
		if (type == dataTypes[i])
			typeHandlers[i](value);
	}
}
