/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:25:49 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/05 21:53:09 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

typedef struct data
{
	int	id;
	std::string	name;
}Data;

class Serializer {
	private:
		Serializer();//default constructor
	public:
		~Serializer();//default destructor
		Serializer(const Serializer &other);//copy construtor
		const Serializer& operator=(const Serializer &other);//copy assignment operator
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

