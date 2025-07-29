/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:15:29 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 21:15:29 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm{

	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& right);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);
		~ShrubberyCreationForm();

		std::string	getTarget(void) const;
		void		setTarget(const std::string newTarget);
		void		execute(Bureaucrat const &executor) const;
};

#endif