/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:46:16 by hamalmar          #+#    #+#             */
/*   Updated: 2025/08/09 14:37:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("Transform To A Robot!")
{}

RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const std::string newTarget)
: AForm("RobotomyRequestForm", 72, 45), target(newTarget)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &right)
: AForm(right), target(right.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &right){
    if (this != &right){
        AForm::operator=(right);
        this->target = right.target;
    }
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const{return (this->target);}
void        RobotomyRequestForm::setTarget(const std::string newTarget){this->target = newTarget;}

void    RobotomyRequestForm::execute(Bureaucrat const &executer) const{
    if (executer.getGrade() > this->getReqGradeToExec()){
        throw AForm::GradeTooLowException();
    }
    if (!this->getIsSigned()){
        throw AForm::FormNotSignedException();
    }
    if (rand() % 2)
	    std::cout << target << " has been robotomized successfully!" << std::endl;
    else
	    std::cout << "The robotomy failed." << std::endl;
}
