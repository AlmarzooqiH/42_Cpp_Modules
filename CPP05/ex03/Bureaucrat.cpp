/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:11:18 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/24 20:11:18 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: name("Hamad"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name), grade(grade)
{}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& right)
 : name(right.name)
{
	this->grade = right.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& right){
	if (this != &right){
		this->grade = right.grade;
	}
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade Is Too High!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade Is Too Low!");
}

std::string Bureaucrat::getName(void) const{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->grade);
}


void	Bureaucrat::setGrade(int newGrade){
	if (newGrade < 1) {throw GradeTooHighException();}
	else if (newGrade > 150) {throw GradeTooLowException();}
	this->grade = newGrade;
}

void	Bureaucrat::incrementGrade(void){
	if ((this->grade - 1) < 1)
	{
		throw GradeTooHighException();
	}
	this->grade--;
}

void	Bureaucrat::decrementGrade(void){
	if ((this->grade + 1) > 150){
		throw GradeTooLowException();
	}
	this->grade++;
}

void	Bureaucrat::signForm(AForm& f){
	try{
		f.beSigned(*this);
		std::cout << this->name << " Signed " << f.getName() << std::endl;
	} catch (std::exception& err){
		std::cout << this->name << " couldn’t sign " << f.getName() << " because " << err.what() << std::endl;	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}


void	Bureaucrat::executeForm(AForm const & form) const{
	try{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (std::exception &err){
		std::cout << this->name << " Couldn\'t Execute " << form.getName()
			<< " Due To " << err.what() << std::endl;
	}
}
