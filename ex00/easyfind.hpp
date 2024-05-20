/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:29:48 by psalame           #+#    #+#             */
/*   Updated: 2024/05/20 14:47:30 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &lst, int value)
{
	return (std::find(lst.begin(), lst.end(), value));
	// for (typename T::iterator i = lst.begin(); i != lst.end(); i++)
	// 	if (*i == value)
	// 		return (i);
	// return (lst.end());
}

#endif