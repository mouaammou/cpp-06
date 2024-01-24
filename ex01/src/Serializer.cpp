/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:31:00 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/05 05:31:54 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

const Serializer&	Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*  Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

