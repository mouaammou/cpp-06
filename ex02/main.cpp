/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouaammo <mouaammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:52:24 by mouaammo          #+#    #+#             */
/*   Updated: 2023/11/06 11:28:29 by mouaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Base.hpp"
#include "inc/A.hpp"
#include "inc/B.hpp"
#include "inc/C.hpp"

Base *generate(void)
{
	int randomInstance = std::rand() % 3;//generate a random number between 0 --> N-1
	if (randomInstance == 0)
		return new A();
	if (randomInstance == 1)
		return new B();
	if (randomInstance == 2)
		return new C();
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		Base &derivedRef = dynamic_cast<A &>(p);
		(void)derivedRef;
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e){}
	try
	{
		Base &derivedRef = dynamic_cast<B &>(p);
		(void)derivedRef;
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e){}
	try
	{
		Base &derivedRef = dynamic_cast<C &>(p);
		(void)derivedRef;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERR: An Exception ocurred ";
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	try
	{
		std::srand(std::time(NULL));
		Base *instance = generate();
		if (!instance)
			throw "ERROR: NULL pointer";
		identify(instance);
		identify(*instance);

		delete instance;
	}
	catch (const char *e)
	{
		std::cerr << e << '\n';
	}

	return 0;
}
