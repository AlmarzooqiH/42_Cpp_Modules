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

#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm{

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& right);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& right);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif