/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:30:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/23 21:49:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T& cHamad, int element);

template <typename T>
typename T::const_iterator easyfind(const T& cHamad, int element);

class ElementNotFoundException: public std::exception{
    public:
        const char* what() const throw();
};

# include "easyfind.tpp"
#endif