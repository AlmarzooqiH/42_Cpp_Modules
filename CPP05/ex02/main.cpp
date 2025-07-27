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


int main(void){
	Bureaucrat hamad;
	Bureaucrat larry("Larry", 5);
	AForm roi;
	AForm renewID("ID Renewal", 150, 1);

	try {
		hamad.signForm(roi);
	} catch (std::exception& err){
		std::cout << err.what() << std::endl;
	}
	try {
		larry.signForm(renewID);
	} catch (std::exception& err){
		std::cout << err.what() << std::endl;
	}

	if (!renewID.getIsSigned()){
		try {
			hamad.signForm(renewID);
		} catch (std::exception& err){
			std::cout << err.what() << std::endl;
		}
	}

	return (0);
}

