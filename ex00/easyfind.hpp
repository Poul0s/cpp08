/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:29:48 by psalame           #+#    #+#             */
/*   Updated: 2024/04/29 20:14:50 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
bool	easyfind(T &lst, int value)
{
	for (T::iterator i = lst.begin(); i != lst.end(); i++)
		if (lst.at(i) == value)
			return (true);
	return (false);
}

#endif