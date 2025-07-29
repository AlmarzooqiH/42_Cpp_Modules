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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	Bureaucrat hamad;
	Bureaucrat larry("Larry", 5);
	AForm *roi = new ShrubberyCreationForm("Withdraw ROI");
	AForm *robot = new RobotomyRequestForm("Transform Into A Robot");

	try{
		roi->beSigned(hamad);
		hamad.executeForm(*roi);
	} catch (std::exception &err){
		std::cout << err.what() << std::endl;
	}
	delete roi;
	return (0);
}

