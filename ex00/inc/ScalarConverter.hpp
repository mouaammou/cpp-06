/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:46:26 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/07 09:40:42 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <limits>
#include <sstream>

typedef struct types
{
	long _int;
	float _float;
	double _double;
	char _char;
} t_types;

class ScalarConverter
{
	private:
		static std::string data_value;
		static t_types data;
		static bool not_number;
		static int impossible[2];
		// canonial form
		ScalarConverter();												// default constructor

	public:
		~ScalarConverter();												// default destructor
		ScalarConverter(const ScalarConverter &other);					// copy construtor
		const ScalarConverter &operator=(const ScalarConverter &other); // copy assignment operator
		
		// map of the class
		static bool is_integer(const std::string &str, long &mynumber);
		static bool is_float(std::string str, float &mynumber);
		static bool is_double(std::string str, double &mynumber);
		static bool is_char(std::string str);
	
		static void check_char(int mynumber);

		static void print_char();
		static void print_int();
		static void print_float();
		static void print_double();
		static void display_converstion();
		/// the convert function required by the subject
		static void convert(std::string str);
		static void set_value(const std::string &input);
};
