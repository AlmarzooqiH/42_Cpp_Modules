/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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
# include <fstream>
# include <string>

class Bureaucrat;

class AForm{

    private:
        const std::string name;
        bool isSigned;
        const int reqGrade;
        const int reqGradeToExec;
    public:
        AForm();
        AForm(const AForm& right);
        AForm& operator=(const AForm& right);
        AForm (const std::string name, int reqGrade, int reqGradeToExec);
        virtual ~AForm();

        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getReqGrade(void) const;
        int         getReqGradeToExec(void) const;
        
        void    beSigned(Bureaucrat& b);
        friend std::ostream& operator<<(std::ostream& os, const AForm& f);

        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class FormNotSignedException: public std::exception{
            public:
                const char *what() const throw();
        };
};

#endif