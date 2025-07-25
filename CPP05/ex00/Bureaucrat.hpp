/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:23:11 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/24 19:23:11 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat{

    private:
        std::string name;
        int         grade;
    
    public:
        
        class GradeTooHighException: public std::exception{
            public:
                const char * what() const throw(){
                    return ("Grade is too high!");
                }
        };
        class GradeTooLowException: public std::exception{
            public:
                const char * what() const throw(){
                    return ("Grade is too low!");
                }
        };
    
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &right);
        Bureaucrat& operator=(const Bureaucrat &right);
        std::string getName(void) const;
        int         getGrade(void) const;
        void        setName(const std::string newName);
        void        setGrade(int newGrade);
        void        incrementGrade(void);
        void        decrementGrade(void);
        
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

};

#endif