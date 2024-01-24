/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:24:52 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/07 09:37:42 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Serializer.hpp"

int main()
{
	// Create a Data object
	Data data;
	data.id = 10;
	data.name = "WINTER IS COMMING";
	// Serialize the Data object
	uintptr_t serialized = Serializer::serialize(&data);

	// Deserialize the serialized value
	Data* deserialized = Serializer::deserialize(serialized);

	// Compare the original pointer and deserialized pointer
	if (deserialized == &data)
		std::cout << "Successful!" << std::endl;
	else
		std::cout << "Failed!" << std::endl;
	return 0;
}
