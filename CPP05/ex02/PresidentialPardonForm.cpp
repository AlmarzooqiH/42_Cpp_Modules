/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:25:45 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/30 00:31:53 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("Get Out Of Jail")
{}

PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& right)
: AForm(right), target(right.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& right){
	if (this != &right){
		AForm::operator=(right);
		this->target = right.target;
	}
	return (*this);
}


std::string	PresidentialPardonForm::getTarget(void) const {return (this->target);}
void		PresidentialPardonForm::setTarget(const std::string newTarget){this->target = newTarget;}

void		PresidentialPardonForm::execute(Bureaucrat const &executer) const{
	if (executer.getGrade() > this->getReqGradeToExec()){
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()){
		throw AForm::FormNotSignedException();
	}
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
