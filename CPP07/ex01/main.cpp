/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:36:01 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/11 16:24:10 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

int main(void){
    int arrI[] = {10, 8, 2003};
    std::string arrS[] = {"Hamad", "Jeff", "Larson", "Ahmed", "Zayed", "Khalifa"};
    float arrF[] = {234.54312f, 20494.12123f, 111111.1f, 0.0f, 10.0f};

    std::cout << "--- Integers ---" << std::endl;
    iter(arrI, sizeof(arrI) / sizeof(arrI[0]), printElement<int>);

    std::cout << "--- Strings ---" << std::endl;
    iter(arrS, sizeof(arrS) / sizeof(arrS[0]), printElement<std::string>);

    std::cout << "--- Floats ---" << std::endl;
    iter(arrF, sizeof(arrF) / sizeof(arrF[0]), printElement<float>);

    iter(arrI, sizeof(arrI) / sizeof(arrI[0]), modifyElement<int>);

    std::cout << "--- Integers ---" << std::endl;
    iter(arrI, sizeof(arrI) / sizeof(arrI[0]), printElement<int>);
    return (0);
}
