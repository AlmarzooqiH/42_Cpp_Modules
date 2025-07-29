/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:09:55 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/29 20:09:24 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm{
	private:
        std::string target;
    
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string newTarget);
        RobotomyRequestForm(const RobotomyRequestForm &right);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &right);
		std::string getTarget(void) const;
        void        setTarget(const std::string newTarget);
        void        execute(Bureaucrat const &executor) const;
    };
#endif