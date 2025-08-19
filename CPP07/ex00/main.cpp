/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:04:59 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/19 11:47:14 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"


/*
    My test cases will uncomment them during the eval.
    for now i will use the main from the subejct file
*/
// int main(void){
//     int x = 2003;
//     int y = 108;

//     std::cout << "X & Y values before swaping" << std::endl << "X: " << x << " and Y: " << y << std::endl;
//     ::swap<int>(x, y);
//     std::cout << std::endl << "X & Y values after swaping" << std::endl << "X: " << x << " and Y: " << y << std::endl;
//     std::cout << std::endl << "Checking min and max values of x and y" << std::endl;
//     std::cout << "min(" << x << ", " << y << "): " << ::min<int>(x, y) << std::endl;
//     std::cout << "max(" << x << ", " << y << "): " << ::max<int>(x, y) << std::endl;
//     std::cout << std::endl;
//     float xf = 2003.108;
//     float yf = 108.2003;

//     std::cout << "Xf & Yf values before swaping" << std::endl << "Xf: " << xf << " and Yf: " << yf << std::endl;
//     ::swap<float>(xf, yf);
//     std::cout << std::endl << "Xf & Yf values after swaping" << std::endl << "Xf: " << xf << " and Yf: " << yf << std::endl;
//     std::cout << std::endl << "Checking min and max values of xf and yf" << std::endl;
//     std::cout << "min(" << xf << ", " << yf << "): " << ::min<float>(xf, yf) << std::endl;
//     std::cout << "max(" << xf << ", " << yf << "): " << ::max<float>(xf, yf) << std::endl;
//     return (0);
// }


//This main is from the subject file.
int main(void) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}
