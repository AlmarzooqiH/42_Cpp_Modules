/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:53:10 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 17:53:10 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("Return On Investment"), isSigned(false), reqGrade(1), reqGradeToExec(1)
{}

Form::~Form(){}

Form::Form(const std::string name, int reqGrade, int reqGradeToExec)
	: name(name), isSigned(false), reqGrade(reqGrade), reqGradeToExec(reqGradeToExec)
{
	if (reqGrade < 1 || reqGradeToExec < 1)
		throw Form::GradeTooHighException();
	if (reqGrade > 150 || reqGradeToExec > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form& right)
	: name(right.name), isSigned(right.isSigned), reqGrade(right.reqGrade), reqGradeToExec(right.reqGradeToExec)
{}
Form& Form::operator=(const Form& right){
	if (this != &right){
		this->isSigned = right.isSigned;
	}
	return (*this);
}

const char	*Form::GradeTooHighException::what() const throw(){
	return ("Grade Is Too High!");
}

const char	*Form::GradeTooLowException::what() const throw(){
	return ("Grade Is Too Low!");
}

const char *Form::FormAlreadyBeenSignedException::what() const throw(){
	return ("This form has been already signed");
}

std::string Form::getName(void) const {return (this->name);}
bool		Form::getIsSigned(void) const {return (this->isSigned);}
int			Form::getReqGrade(void) const {return (this->reqGrade);}
int			Form::getReqGradeToExec(void) const {return (this->reqGradeToExec);}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << "Form name: " << f.getName() << " , isSigned: " <<
	f.getIsSigned() << " , reqGrade: " << f.getReqGrade() <<
	" , ReqGradeToExec: " << f.getReqGradeToExec();
	return (os);
}

void	Form::beSigned(Bureaucrat& b){
	if (this->isSigned){
		throw Form::FormAlreadyBeenSignedException();
	}
	if (b.getGrade() > this->reqGrade){
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}
