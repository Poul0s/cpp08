/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:35:28 by psalame           #+#    #+#             */
/*   Updated: 2024/05/05 22:26:01 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<class T>
class MutantStack : public std::stack<T> {
	public:
		// MutantStack();
		// MutantStack(const MutantStack &src);
		// ~MutantStack();

		// MutantStack &operator=(const MutantStack &src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

// template<class T>
// MutantStack<T>::MutantStack() : std::stack<T>()
// {
// }

// template<class T>
// MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
// {
// }

// template<class T>
// MutantStack<T>::~MutantStack()
// {
// }

// template<class T>
// MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
// {
// 	std::stack<T>::operator=(src);
// 	return *this;
// }

#include "MutantStack.tpp"

#endif