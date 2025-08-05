/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:14:52 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 19:14:52 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
    std::srand(std::time(NULL));

    Bureaucrat hamad("Hamad", 1);
    Bureaucrat ahmed("Ahmed", 50);
    Bureaucrat larry("Larry", 145);
    AForm *shrubbery = new ShrubberyCreationForm("Collect Tax");
    AForm *bender    = new RobotomyRequestForm("Transform Into A Bender");
    AForm *evadeTax  = new PresidentialPardonForm("Tax Evader");

    std::cout << std::endl;
    hamad.executeForm(*shrubbery);
    std::cout << std::endl;

    larry.signForm(*shrubbery);
    larry.executeForm(*shrubbery);
    std::cout << std::endl;

    ahmed.executeForm(*shrubbery);
    ahmed.signForm(*bender);
    ahmed.executeForm(*bender);
    std::cout << std::endl;

    hamad.executeForm(*bender);
    std::cout << std::endl;

    larry.signForm(*evadeTax);
    std::cout << std::endl;

    ahmed.signForm(*evadeTax);
    ahmed.executeForm(*evadeTax);
    std::cout << std::endl;

    hamad.signForm(*evadeTax);
    hamad.executeForm(*evadeTax);

    delete shrubbery;
    delete bender;
    delete evadeTax;
    return (0);
}

