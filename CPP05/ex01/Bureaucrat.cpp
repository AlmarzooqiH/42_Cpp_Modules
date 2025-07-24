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

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name, int grade){
	this->name = name;
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& right){
	this->name = right.name;
	this->grade = right.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& right){
	if (this != &right){
		this->name = right.name;
		this->grade = right.grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->grade);
}

void	Bureaucrat::setName(const std::string newName){
	this->name = newName;
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

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
