/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:36:01 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/19 13:26:32 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

int main(void){
    int arrI[] = {10, 8, 2003};
    std::string arrS[] = {"Hamad", "Jeff", "Larson", "Ahmed", "Zayed", "Khalifa"};

    const int arrCI[] = {10, 8, 2003};
    const std::string arrCS[] = {"Hamad", "Jeff", "Larson", "Ahmed", "Zayed", "Khalifa"};

    std::cout << "Printing Integer Array" << std::endl;
    iter(arrI, (sizeof(arrI) / (sizeof(arrI[0]))), printElement<int>);
    
    std::cout << "============================" << std::endl;
    
    std::cout << "Printing string Array" << std::endl;
    iter(arrS, (sizeof(arrS) / (sizeof(arrS[0]))), printElement<std::string>);

    std::cout << "============================" << std::endl;
    std::cout << "Printing Const Integer Array" << std::endl;
    iter(arrCI, (sizeof(arrCI) / (sizeof(arrCI[0]))), printElement<const int>);

    std::cout << "============================" << std::endl;

    std::cout << "Printing const string Array" << std::endl;
    iter(arrCS, (sizeof(arrCS) / (sizeof(arrCS[0]))), printElement<const std::string>);
    return (0);
}
