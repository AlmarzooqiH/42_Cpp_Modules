/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:53:10 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 17:53:10 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: name("Return On Investment"), isSigned(false), reqGrade(1), reqGradeToExec(1)
{}

AForm::~AForm(){}

AForm::AForm(const std::string name, int reqGrade, int reqGradeToExec)
	: name(name), isSigned(false), reqGrade(reqGrade), reqGradeToExec(reqGradeToExec)
{
	if (reqGrade < 1 || reqGradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (reqGrade > 150 || reqGradeToExec > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& right)
	: name(right.name), isSigned(right.isSigned), reqGrade(right.reqGrade), reqGradeToExec(right.reqGradeToExec)
{}
AForm& AForm::operator=(const AForm& right){
	if (this != &right){
		this->isSigned = right.isSigned;
	}
	return (*this);
}

const char	*AForm::GradeTooHighException::what() const throw(){
	return ("Grade Is Too High!");
}

const char	*AForm::GradeTooLowException::what() const throw(){
	return ("Grade Is Too Low!");
}

const char *AForm::FormAlreadyBeenSignedException::what() const throw(){
	return ("This form has been already signed");
}

const char *AForm::FormNotSignedException::what() const throw(){
	return ("The Form Is Not Signed!");
}

std::string AForm::getName(void) const {return (this->name);}
bool		AForm::getIsSigned(void) const {return (this->isSigned);}
int			AForm::getReqGrade(void) const {return (this->reqGrade);}
int			AForm::getReqGradeToExec(void) const {return (this->reqGradeToExec);}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << "Form name: " << f.getName() << " , isSigned: " << f.getIsSigned() << " , reqGrade: " << f.getReqGrade() << " , ReqGradeToExec: " << f.getReqGradeToExec();
	return (os);
}

void	AForm::beSigned(Bureaucrat& b){
	if (this->isSigned){
		throw AForm::FormAlreadyBeenSignedException();
	}
	if (b.getGrade() > this->reqGrade){
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}
