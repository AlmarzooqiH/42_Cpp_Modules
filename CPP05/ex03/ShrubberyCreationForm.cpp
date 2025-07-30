/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:20:09 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 21:20:09 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm::AForm("ShrubberyCreationForm", 145, 137), target("Get Money From ROI")
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string newTarget)
: AForm("ShrubberyCreationForm", 145, 137), target(newTarget)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& right)
: AForm(right), target(right.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& right)
{
    if (this != &right){
        AForm::operator=(right);
        this->target = right.target;
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const{return (this->target);}
void        ShrubberyCreationForm::setTarget(const std::string newTarget){this->target = newTarget;}

void    ShrubberyCreationForm::execute(Bureaucrat const &executer) const{
    if (executer.getGrade() > this->getReqGradeToExec()){
        throw AForm::GradeTooLowException();
    }
    if (!this->getIsSigned()){
        throw AForm::FormNotSignedException();
    }
    std::ofstream out((this->target + "_shrubbery").c_str());
    if (!out){
        std::cerr << "Failed to create a file" << std::endl;
        return ;
    }
    out << "                               ASCII trees                             " << std::endl;
    out << "                                ********                               " << std::endl;
    out << "                              ***********                              " << std::endl;
    out << "                            ***************                            " << std::endl;
    out << "                           *****************                           " << std::endl;
    out << "                          *******************                          " << std::endl;
    out << "         *               *********************               *         " << std::endl;
    out << "        **              ***********************             **         " << std::endl;
    out << "       ****            *************************           ****        " << std::endl;
    out << "      ******           *************************          ******       " << std::endl;
    out << "     ********          *************************         ********      " << std::endl;
    out << "    **********          ***********************         **********     " << std::endl;
    out << "   ************          *********************         ************    " << std::endl;
    out << "  **************          *******************         **************   " << std::endl;
    out << " ****************          *****************         ****************  " << std::endl;
    out << "        ||                        ||                        ||         " << std::endl;
    out << "        ||                        ||                        ||         " << std::endl;
    out << "        ||                        ||                        ||         " << std::endl;
    out << "        ||                        ||                        ||         " << std::endl;
    out << "=======================================================================" << std::endl;
    out.close();
}
