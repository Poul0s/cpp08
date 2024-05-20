/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:11 by psalame           #+#    #+#             */
/*   Updated: 2024/05/20 14:44:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

void	test1(int &exit_code)
{
	// std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;
	
	// if (::easyfind(vec, 5) != vec.end())
	// {
	// 	std::cout << "Found elem 5 in an empty vector." << std::endl;
	// 	exit_code++;
	// }
	if (::easyfind(deq, 5) != deq.end())
	{
		std::cout << "Found elem 5 in an empty deque." << std::endl;
		exit_code++;
	}
	if (::easyfind(lst, 5) != lst.end())
	{
		std::cout << "Found elem 5 in an empty list." << std::endl;
		exit_code++;
	}
}

void	test2(int &exit_code)
{
	// std::vector<int>	vec;
	// vec.insert(vec.begin(), 6);
	std::deque<int>		deq;
	deq.insert(deq.begin(), 6);
	std::list<int>		lst;
	lst.insert(lst.begin(), 6);
	
	// if (::easyfind(vec, 5) != vec.end())
	// {
	// 	std::cout << "Found elem 5 in vector that doesnt contain it." << std::endl;
	// 	exit_code++;
	// }
	if (::easyfind(deq, 5) != deq.end())
	{
		std::cout << "Found elem 5 in deque that doesnt contain it." << std::endl;
		exit_code++;
	}
	if (::easyfind(lst, 5) != lst.end())
	{
		std::cout << "Found elem 5 in list that doesnt contain it." << std::endl;
		exit_code++;
	}
}

void	test3(int &exit_code)
{
	// std::vector<int>	vec;
	// vec.insert(vec.begin(), 3);
	// vec.insert(vec.begin(), 9);
	// vec.insert(vec.begin(), 5);
	// vec.insert(vec.begin(), 1);
	std::deque<int>		deq;
	deq.insert(deq.begin(), 3);
	deq.insert(deq.begin(), 9);
	deq.insert(deq.begin(), 5);
	deq.insert(deq.begin(), 1);
	std::list<int>		lst;
	lst.insert(lst.begin(), 3);
	lst.insert(lst.begin(), 9);
	lst.insert(lst.begin(), 5);
	lst.insert(lst.begin(), 1);
	
	// if (::easyfind(vec, 5) == vec.end() || *::easyfind(vec, 5) != 5)
	// {
	// 	std::cout << "Didnt found elem 5 in vector that contain it." << std::endl;
	// 	exit_code++;
	// }
	if (::easyfind(deq, 5) == deq.end() || *::easyfind(deq, 5) != 5)
	{
		std::cout << "Didnt found elem 5 in deque that contain it." << std::endl;
		exit_code++;
	}
	if (::easyfind(lst, 5) == lst.end() || *::easyfind(lst, 5) != 5)
	{
		std::cout << "Didnt found elem 5 in list that contain it." << std::endl;
		exit_code++;
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

	return exit_code;
}
