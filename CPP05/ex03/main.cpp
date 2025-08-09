/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:14:52 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/30 12:00:00 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){
    std::srand(std::time(NULL));

    Bureaucrat hamad("Hamad", 1);
    Bureaucrat ahmed("Ahmed", 50);
    Bureaucrat larry("Larry", 145);
    Intern     slave;

    AForm *shrubbery = new ShrubberyCreationForm("Collect Tax");
    AForm *bender    = new RobotomyRequestForm("Transform Into A Bender");
    AForm *taxEvader  = nullptr;

    std::cout << "Intern creating a form with invalid format" << std::endl;
    
    try{
        taxEvader = slave.makeForm("t", "Tax Evader");
    } catch (std::exception& err){
        std::cerr << err.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Intern creating a form with valid format" << std::endl;

    try{
        taxEvader = slave.makeForm("p", "Tax Evader");
    } catch (std::exception& err){
        std::cerr << err.what() << std::endl;
    }

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

    if (taxEvader != nullptr){
    larry.signForm(*taxEvader);
    std::cout << std::endl;

    ahmed.signForm(*taxEvader);
    ahmed.executeForm(*taxEvader);
    std::cout << std::endl;

    hamad.signForm(*taxEvader);
    hamad.executeForm(*taxEvader);
    }
    delete shrubbery;
    delete bender;
    delete taxEvader;
    return (0);
}

