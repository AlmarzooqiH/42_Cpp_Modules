/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:54:03 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 22:45:55 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << "The address of the string: " << &str << std::endl;
    std::cout << "The address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "The address of the stringPTR: " << &stringREF << std::endl;
    std::cout << "The string Data: " << str << std::endl;
    std::cout << "The stringPTR Data: " << *stringPTR << std::endl;
    std::cout << "The stringREF Data: " << stringREF << std::endl;
    return 0;
}
