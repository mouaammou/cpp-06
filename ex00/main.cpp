/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:38:53 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/07 08:24:20 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::set_value(av[1]);
	else
		std::cout << "ERROR: bas arguments, please try again" << std::endl;
	return (0);
}
