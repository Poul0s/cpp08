/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:11 by psalame           #+#    #+#             */
/*   Updated: 2024/05/05 22:30:07 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

void	test1(int &exit_code)
{
	MutantStack<int>	mstack;
	std::list<int>		lst;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	MutantStack<int>::iterator	msit = mstack.begin();
	std::list<int>::iterator	lit = lst.begin();
	while (msit != mstack.end())
	{
		if (*msit != *lit)
		{
			exit_code += 1;
			std::cerr << "Value in mstack is different from list." << std::endl;
		}
		++msit;
		++lit;
	}
}

void	test2(int &exit_code)
{
	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	if (mstack.top() != 3)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 3." << std::endl;
	}
	mstack.pop();

	if (mstack.top() != 2)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 2." << std::endl;
	}
	mstack.pop();

	if (mstack.top() != 1)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 1." << std::endl;
	}
}

void	test3(int &exit_code)
{
	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>	mstack2(mstack);

	if (mstack2.top() != 3)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 3." << std::endl;
	}
	mstack2.pop();

	if (mstack2.top() != 2)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 2." << std::endl;
	}
	mstack2.pop();

	if (mstack2.top() != 1)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 1." << std::endl;
	}
}

void	test4(int &exit_code)
{
	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>	mstack2;

	mstack2 = mstack;

	if (mstack2.top() != 3)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 3." << std::endl;
	}
	mstack2.pop();

	if (mstack2.top() != 2)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 2." << std::endl;
	}
	mstack2.pop();

	if (mstack2.top() != 1)
	{
		exit_code += 1;
		std::cerr << "Top value isnt equal to 1." << std::endl;
	}

}

void	test_launcher(int &exit_code, void (*test_fct)(int &), int test_nb)
{
	int	prev_exit_code = exit_code;

	try
	{
		(*test_fct)(exit_code);
	}
	catch (std::exception &err)
	{
		exit_code += 1;
		std::cerr << "Unhandled exception in test : " << err.what() << std::endl;
	}
	if (exit_code != prev_exit_code)
		std::cout << "Test " << test_nb << " : failed." << std::endl;
	else
		std::cout << "Test " << test_nb << " : success." << std::endl;
}

int	main(void)
{
	int	exit_code = 0;
	int	test_nb = 1;

	test_launcher(exit_code, &test1, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test2, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test3, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test4, test_nb++);

	return exit_code;
}
