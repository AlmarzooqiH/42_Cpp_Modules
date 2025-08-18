/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:49:48 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/17 20:29:20 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void    easyfind(const T& container, int element){
    for(size_t i = 0; i < container.size(); i++){
        if (container.at(i) == element)
            return ;
    }
	throw (ElementNotFoundException());
}
