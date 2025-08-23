/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:49:48 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/23 21:49:37 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T& cHamad, int element){
    typename T::iterator hamad = std::find(cHamad.begin(), cHamad.end(), element);
    if (hamad == cHamad.end())
        throw (ElementNotFoundException());
    return (hamad);
}

template <typename T>
typename T::const_iterator easyfind(const T& cHamad, int element){
    typename T::const_iterator hamad = std::find(cHamad.begin(), cHamad.end(), element);
    if (hamad == cHamad.end())
        throw (ElementNotFoundException());
    return (hamad);
}
