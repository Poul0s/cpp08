/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:06:11 by psalame           #+#    #+#             */
/*   Updated: 2024/05/03 15:45:17 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>

void	test1(int &exit_code)
{
	Span sp = Span(2);
	sp.addNumber(6);
	sp.addNumber(3);

	try {
		sp.addNumber(1);
		exit_code++;
		std::cerr << "Can insert number in a full Span." << std::endl;
	} catch (Span::SpanFullException &exception)
	{
	}
}

void	test2(int &exit_code)
{
	Span sp = Span(5);
	sp.addNumber(6);

	try {
		sp.longestSpan();
		exit_code++;
		std::cerr << "Can search longest span in a Span that contain only one value." << std::endl;
	}
	catch (Span::SpanTooShortException &exception)
	{
	}
}

void	test3(int &exit_code)
{
	Span sp = Span(5);
	sp.addNumber(6);

	try {
		sp.shortestSpan();
		exit_code++;
		std::cerr << "Can search shortest span in a Span that contain only one value." << std::endl;
	}
	catch (Span::SpanTooShortException &exception)
	{
	}
}

void	test4(int &exit_code)
{
	Span sp = Span(5);

	try {
		sp.longestSpan();
		exit_code++;
		std::cerr << "Can search longest span in a empty Span." << std::endl;
	}
	catch (Span::SpanTooShortException &exception)
	{
	}
}

void	test5(int &exit_code)
{
	Span sp = Span(5);
	sp.addNumber(6);

	try {
		sp.shortestSpan();
		exit_code++;
		std::cerr << "Can search shortest span in a empty Span." << std::endl;
	}
	catch (Span::SpanTooShortException &exception)
	{
	}
}

void	test6(int &exit_code)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	if (sp.shortestSpan() != 2)
	{
		std::cerr << "Bad value for shortest span (" << sp.shortestSpan() << ")." << std::endl;
		exit_code++;
	}
	if (sp.longestSpan() != 14)
	{
		std::cerr << "Bad value for longest span (" << sp.longestSpan() << ")." << std::endl;
		exit_code++;
	}
}

void	test7(int &exit_code)
{
	Span sp = Span(2);
	sp.addNumber(-2147483648);
	sp.addNumber(2147483647);
	unsigned int expectedShortest = 4294967295;
	unsigned int expectedLongest = 4294967295;

	if (sp.shortestSpan() != expectedShortest)
	{
		std::cerr << "Bad value for shortest span (" << sp.shortestSpan() << ")." << std::endl;
		exit_code++;
	}
	if (sp.longestSpan() != expectedLongest)
	{
		std::cerr << "Bad value for longest span (" << sp.longestSpan() << ")." << std::endl;
		exit_code++;
	}
}

void	test8(int &exit_code)
{
	std::vector<int>	vec;
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);
	Span sp = Span(5);

	sp.insert(vec.begin(), vec.end());
	if (sp.shortestSpan() != 2)
	{
		std::cerr << "Bad value for shortest span (" << sp.shortestSpan() << ")." << std::endl;
		exit_code++;
	}
	if (sp.longestSpan() != 14)
	{
		std::cerr << "Bad value for longest span (" << sp.longestSpan() << ")." << std::endl;
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
	std::cout << std::endl;
	test_launcher(exit_code, &test4, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test5, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test6, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test7, test_nb++);
	std::cout << std::endl;
	test_launcher(exit_code, &test8, test_nb++);

	return exit_code;
}
