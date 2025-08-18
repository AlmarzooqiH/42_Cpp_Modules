/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:30:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/17 20:29:51 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>


template <typename T>
void easyfind(const T& container, int element);

class ElementNotFoundException: public std::exception{
    public:
        const char* what() const throw();
};

# include "easyfind.tpp"
#endif