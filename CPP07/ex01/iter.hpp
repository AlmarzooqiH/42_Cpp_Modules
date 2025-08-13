/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:36:21 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/13 15:55:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename Hamad, typename Function>
void iter(Hamad* addr, size_t size, Function f){
    for (size_t i = 0; i < size; i++){
        f(addr[i]);
    }
}

template <typename Hamad, typename Function>
void iter(const Hamad* addr, size_t size, Function f){
    for (size_t i = 0; i < size; i++){
        f(addr[i]);
    }
}

template <typename Hamad>
void printElement(Hamad& element){
    std::cout << element << std::endl;
}

#endif