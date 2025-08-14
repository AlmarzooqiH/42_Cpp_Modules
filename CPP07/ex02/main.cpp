/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:28:08 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/14 20:44:31 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

int main(void){
	Array<int> *arr = new Array<int>(5);
	for (unsigned int i = 0; i < arr->size(); i++){
		(*arr)[i] = i * i * i;
	}
	for (unsigned int i = 0; i < arr->size(); i++){
		std::cout << (*arr)[i] << std::endl;
	}
	
	delete (arr);
	return (0);
}
