/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:28:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/30 13:36:21 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern &right);
		Intern& operator=(const Intern &right);
		~Intern();

		AForm*	makeForm(const std::string formName, const std::string formTarget);

		class	FormNotCreatedException: public std::exception{
			public:
				const char *what() const throw();
		};
};
#endif