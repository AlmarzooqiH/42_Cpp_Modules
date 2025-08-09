/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:35:58 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/09 15:58:48 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &right){
	(void)right;
}
Intern& Intern::operator=(const Intern &right){
	(void)right;
	return (*this);
}

Intern::~Intern(){}

AForm*	Intern::makeForm(const std::string formName, const std::string formTarget){
	std::string lowerName = formName;
	std::string formType = "";
	for (size_t i = 0; i < formName.length(); i++){
		lowerName[i] = std::tolower(formName[i]);
	}
	AForm* newForm = NULL;
	switch (lowerName[0]){
		case 's':
			newForm = new ShrubberyCreationForm(formTarget);
			formType = "ShrubberyCreationForm";
			break;
		case 'r':
			newForm = new RobotomyRequestForm(formTarget);
			formType = "RobotomyRequestForm";
			break;
		case 'p':
			newForm = new PresidentialPardonForm(formTarget);
			formType = "PresidentialPardonForm";
			break;
		default:
			newForm = NULL;
			break;
	}	
	if (!newForm)
			throw Intern::FormNotCreatedException();
	std::cout << "Intern has created " << formType << std::endl;
	return (newForm);
}

const	char	*Intern::FormNotCreatedException::what() const throw(){
	return ("Failed To Create Form Due To Invalid Format!");
}
