/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:34:51 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/11 15:35:01 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template <typename Hamad>
void swap(Hamad& h1, Hamad& h2){
    Hamad tmp = h1;
    h1 = h2;
    h2 = tmp;
}

template <typename Hamad>
Hamad min(Hamad& h1, Hamad& h2){
    return ((h1 > h2) ? h2 : h1);
}

template <typename Hamad>
Hamad max(Hamad& h1, Hamad& h2){
    return ((h1 > h2) ? h1 : h2);
}

#endif