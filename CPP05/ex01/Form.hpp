/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:21:24 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/24 21:21:24 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form{

    private:
        const std::string name;
        bool isSigned;
        const int reqGrade;
        const int reqGradeToExec;

    public:
        Form();
        Form(const Form& right);
        Form& operator=(const Form& right);
        Form (const std::string name, int reqGrade, int reqGradeToExec);
        ~Form();

        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getReqGrade(void) const;
        int         getReqGradeToExec(void) const;
        
        void    beSigned(Bureaucrat& b);
        friend std::ostream& operator<<(std::ostream& os, const Form& f);

        class GradeTooLowException: public std::exception{
            public:
                const char *what() const throw();
        };

        class GradeTooHighException: public std::exception{
            public:
                const char *what() const throw();
        };
        
        class FormAlreadyBeenSignedException: public std::exception{
            public:
                const char *what() const throw();
        };
};

#endif