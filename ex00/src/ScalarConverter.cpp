/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:52:43 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/07 13:23:06 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

std::string ScalarConverter::data_value;
t_types ScalarConverter::data;
bool ScalarConverter::not_number = false;
int ScalarConverter::impossible[2] = {0, 0};

ScalarConverter::ScalarConverter(){};  // default constructor
ScalarConverter::~ScalarConverter(){}; // default destructor

// copy construtor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

// copy assignment operator
const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		this->data_value = other.data_value;
		this->data = other.data;
		this->not_number = other.not_number;
		for (size_t i = 0; i < 2; i++)
			this->impossible[i] = other.impossible[i];
	}
	return (*this);
}

void ScalarConverter::check_char(int mynumber) //* ******** CHECK === > char
{
	if (mynumber < 0 || mynumber > 255)
		impossible[0] = 1;
}

// IS === > char, int , float , double
bool ScalarConverter::is_char(std::string str)
{
	return (str.length() == 1 && isprint(str[0]));
}

bool ScalarConverter::is_integer(const std::string &str, long &mynumber)
{
	char *endPtr;
	mynumber = std::strtol(str.c_str(), &endPtr, 10);
	return (*endPtr == '\0');
}

bool ScalarConverter::is_float(std::string str, float &mynumber)
{
	if (str[str.length() - 1] != 'f')
		return (false);
	if (str[str.length() - 1] == 'f')
		str = str.substr(0, str.length() - 1);

	std::stringstream mystream(str);
	mystream >> mynumber;

	if (mystream.fail() || !mystream.eof())
		return (false);
	return (true);
}

bool ScalarConverter::is_double(std::string str, double &mynumber)
{
	if (str[str.length() - 1] == 'f' && (isdigit(str[0]) || str[0] == '-' || str[0] == '+'))
		str = str.substr(0, str.length() - 1);

	std::stringstream mystream(str);
	mystream >> mynumber;
	if (mystream.fail() || !mystream.eof())
		return (false);
	return (true);
}

// ******** PRINT === > char, int , float , double
void ScalarConverter::print_char()
{
	if (not_number == false && impossible[0] == 0 && impossible[1] == 0)
	{
		if (isprint(data._char))
			std::cout << "char: '" << data._char << "'" << std::endl;
		else
			std::cout << "char: '"
					  << "Non displayable"
					  << "'" << std::endl;
	}
	else
		std::cout << "char: '"
				  << "Impossible"
				  << "'" << std::endl;
}

void ScalarConverter::print_int()
{
	if (not_number == false && impossible[1] == 0)
	{
		std::cout << "int: " << data._int << std::endl;
	}
	else
	{
		std::cout << "int: "
				  << "Impossible" << std::endl;
	}
}

void ScalarConverter::print_float()
{
	float number = data._float;
	float integerPart = std::floor(number);
	float decimalPart = number - integerPart;
	if (not_number == false)
	{
		if (decimalPart == 0)
			std::cout << "float: " << data._float << ".0f" << std::endl;
		else
			std::cout << "float: " << data._float << "f" << std::endl;
	}
	else
	{
		std::cout << "float: "
				  << "nanf" << std::endl;
	}
}

void ScalarConverter::print_double()
{
	double number = data._double;
	double integerPart = std::floor(number);
	double decimalPart = number - integerPart;
	if (not_number == false)
	{
		if (decimalPart == 0)
			std::cout << "double: " << data._double << ".0" << std::endl;
		else
			std::cout << "double: " << data._double << std::endl;
	}
	else
	{
		std::cout << "double: "
				  << "nan" << std::endl;
	}
}

// PRINT ALL
void ScalarConverter::display_converstion()
{
	print_char();
	print_int();
	print_float();
	print_double();
}

// COVERT === > char, int , float , double
void ScalarConverter::convert(std::string str)
{
	if (is_double(str, data._double))
	{
		data._float = static_cast<float>(data._double);
		data._int = static_cast<int>(data._double);
		data._char = static_cast<char>(data._double);
		check_char(data._int);
		if (data._double > INT_MAX || data._double < INT_MIN)
			impossible[1] = 1;
	}
	else if (is_char(str))
	{
		data._char = data_value[0];
		data._int = static_cast<int>(data._char);
		data._double = static_cast<double>(data._char);
		data._float = static_cast<float>(data._char);
		check_char(data._int);
	}
	else if (is_integer(str, data._int))
	{
		data._double = static_cast<double>(data._int);
		data._float = static_cast<float>(data._int);
		data._char = static_cast<char>(data._int);
		check_char(data._int);
		if (data._int > INT_MAX || data._int < INT_MIN)
			impossible[1] = 1;
	}
	else if (is_float(str, data._float))
	{
		data._int = static_cast<int>(data._float);
		data._double = static_cast<double>(data._float);
		data._char = static_cast<char>(data._float);
		if (data._float > INT_MAX || data._float < INT_MIN)
			impossible[1] = 1;
		check_char(data._int);
	}
	else
		not_number = true;
}

// set value
void ScalarConverter::set_value(const std::string &input)
{
	data_value = input;
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
		impossible[1] = 1;
	convert(input);
	display_converstion();
}
