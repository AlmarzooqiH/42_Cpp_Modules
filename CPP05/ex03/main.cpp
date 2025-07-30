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
    AForm *taxEvader  = slave.makeForm("p", "Tax Evader");

    try{
        hamad.executeForm(*shrubbery);
    } catch (std::exception &err){
        std::cout << err.what() << std::endl;
    }

    larry.signForm(*shrubbery);
    try{
        larry.executeForm(*shrubbery);
    } catch (std::exception &err){
        std::cout << err.what() << std::endl;
    }

    ahmed.executeForm(*shrubbery);

    ahmed.signForm(*bender);
    ahmed.executeForm(*bender);
    hamad.executeForm(*bender);

    larry.signForm(*taxEvader);
    ahmed.signForm(*taxEvader);
    ahmed.executeForm(*taxEvader);
    hamad.signForm(*taxEvader);
    hamad.executeForm(*taxEvader);

    delete shrubbery;
    delete bender;
    delete taxEvader;
    return (0);
}

