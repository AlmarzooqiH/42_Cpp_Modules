/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 22:50:06 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/12 17:05:32 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>

Base* generate(void){
    int   randomNum = rand();

    if (randomNum % 2 == 0){
        return (new A());
    } else if (randomNum % 3 == 0){
        return (new B());
    }
    return (new C());
}

void    identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL){
        std::cout << "P is a pointer to: A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL){
        std::cout << "P is a pointer to: B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL){
        std::cout << "P is a pointer to: C" << std::endl;
    } else {
        std::cout << "P is a pointer to: Is Unkown type" << std::endl;
    }
}

void identify (Base& p){
    try{
        dynamic_cast<A&>(p);
        std::cout << "P is a refernce to: A" << std::endl;
        return ;
    } catch (std::exception& err){}

    try{
        dynamic_cast<B&>(p);
        std::cout << "P is a refernce to: B" << std::endl;
        return ;
    } catch (std::exception& err){}

    try{
        dynamic_cast<C&>(p);
        std::cout << "P is a refernce to: C" << std::endl;
        return ;
    } catch (std::exception& err){}
}

int main(void){
    std::srand(std::time(NULL) + 2003 - (8 * 10));
    for (int i = 0; i < 4; i++){
        Base* randomBase = generate();
        identify(randomBase);
        identify(*randomBase);
        delete randomBase;
    }
    return (0);
}
