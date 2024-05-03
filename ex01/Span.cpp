/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:46:47 by psalame           #+#    #+#             */
/*   Updated: 2024/05/03 15:44:55 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size)
{
	this->_maxSize = size;
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span(void)
{
}

Span	&Span::operator=(const Span &copy)
{
	this->_lst = copy._lst;
	this->_maxSize = copy._maxSize;
	return *this;
}

void	Span::addNumber(int number)
{
	if (this->_lst.size() + 1 > this->_maxSize)
		throw SpanFullException();
	this->_lst.push_back(number);
}

void	Span::insert(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_lst.size() + (end - begin) >= this->_maxSize)
		throw SpanFullException();
	this->_lst.insert(this->_lst.end(), begin, end);
}

unsigned int		Span::shortestSpan(void)
{
	if (this->_lst.size() < 2)
		throw Span::SpanTooShortException();
	std::sort(this->_lst.begin(), this->_lst.end());
	std::vector<int>::iterator	it = this->_lst.begin();
	unsigned int				minSpan = *(it + 1) - *it;
	while (it + 1 != this->_lst.end())
	{
		if ((unsigned int)(*(it + 1) - *it) < minSpan)
			minSpan = *(it + 1) - *it;
		it++;
	}
	return (minSpan);
}

unsigned int		Span::longestSpan(void)
{
	if (this->_lst.size() < 2)
		throw Span::SpanTooShortException();
	std::sort(this->_lst.begin(), this->_lst.end());
	return (*(this->_lst.end() - 1) - *this->_lst.begin());
}

const char	*Span::SpanFullException::what(void) const throw()
{
	return "Cannot add number in Span: Span is full.";
}

const char	*Span::SpanTooShortException::what(void) const throw()
{
	return "Cannot search span: require a minimum number of two in span.";
}