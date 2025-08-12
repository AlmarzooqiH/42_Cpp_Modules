/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:36:21 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/11 16:23:24 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename Hamad>
void iter(Hamad* addr, size_t size, void (*func)(Hamad& element)){
    for (size_t i = 0; i < size; i++){
        func(addr[i]);
    }
}

template <typename Hamad>
void printElement(Hamad& element){
    std::cout << element << std::endl;
}

template <typename Hamad>
void modifyElement(Hamad& element){
    element = static_cast<int>('H');
}

#endif