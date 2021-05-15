/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:35:56 by dmalori           #+#    #+#             */
/*   Updated: 2021/05/15 10:36:21 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define OFF "\033[0m"

static bool is_all_number(std::string input)
{
	for (unsigned long i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input.at(i)))
		{
			if (i == 0 && input.at(i) == '-' && input.size() != 1)
				continue;
			return false;
		}
	}
	return true;
}

int main (int argc, char **argv)
{
	std::string input;
	std::string control_1;
	std::string control_2;
	std::stringstream conv;
	std::stringstream conv_control_1;
	std::stringstream conv_control_2;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	if (argc != 2)
	{
		std::cout << RED << "** ERROR ARGUMENT" << OFF << std::endl;
		return (0);
	}
	input = argv[1];
	//NAN
	if (input == "nanf" || input == "nan")
	{
		std::cout << GREEN << "** NOT A NUMBER" << OFF << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	//+INF
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << GREEN << "** + INFINITY" << OFF << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	//-INF
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << GREEN << "** - INFINITY" << OFF << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	//FLOAT
	else if (input.find(".") != std::string::npos && input[input.size() - 1] == 'f')
	{
		std::cout << GREEN << "** FLOAT" << OFF << std::endl;
		conv.str("");
		conv << input.substr(0, input.size() - 1);
		conv >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		conv_control_1.str("");
		conv_control_1 << d;
		conv_control_1 >> control_1;
		conv_control_2.str("");
		conv_control_2 << i;
		conv_control_2 >> control_2;		
		if (std::isprint(i))
			std::cout << "char: '" << char(i) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (std::round(std::abs(d)) > std::abs(i))
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (control_1.size() == control_2.size())
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;	
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
	//DOUBLE
	else if (input.find(".") != std::string::npos)
	{
		std::cout << GREEN << "** DOUBLE" << OFF << std::endl;
		conv.str("");
		conv << input;
		conv >> d;
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		conv_control_1.str("");
		conv_control_1 << d;
		conv_control_1 >> control_1;
		conv_control_2.str("");
		conv_control_2 << i;
		conv_control_2 >> control_2;
		if (std::isprint(i))
			std::cout << "char: '" << char(i) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (std::round(std::abs(d)) > std::abs(i))
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (control_1.size() == control_2.size())
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;	
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
	//INT
	else if (is_all_number(input))
	{
		std::cout << GREEN << "** INT" << OFF << std::endl;
		conv.str("");
		conv << input;
		conv >> d;
		f = static_cast<float>(d);
		i = static_cast<int>(d);
		if (std::isprint(i))
			std::cout << "char: '" << char(i) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (std::abs(d) > std::abs(i))
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (std::abs(d) >= 1000000)
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;	
		}
		else
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
	}
	// CHAR
	else if (input.size() == 1 && std::isprint(input.at(0)))
	{
		std::cout << GREEN << "** CHAR" << OFF << std::endl;
		conv.str("");
		conv << int(input.at(0));
		conv >> i;
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		std::cout << "char: '" << input << "'"<< std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;	
	}
	// IMPOSSIBLE
	else
	{
		std::cout << RED << "** CONVERSION IMPOSSIBLE" << OFF << std::endl;
	}

	return (0);
}
