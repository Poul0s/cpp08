/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:30:41 by psalame           #+#    #+#             */
/*   Updated: 2024/05/03 15:48:28 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <exception>
# include <vector>

class Span {
	public:
		Span(unsigned int size);
		Span(const Span &copy);
		~Span(void);

		Span	&operator=(const Span &copy);

		void				addNumber(int number);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		void				insert(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
		class	SpanFullException;
		class	SpanTooShortException;
	
	private:
		unsigned int		_maxSize;
		std::vector<int>	_lst;
};

class Span::SpanFullException : std::exception {
	public:
		const char	*what(void) const throw();
};

class Span::SpanTooShortException : std::exception {
	public:
		const char	*what(void) const throw();
};

#endif
