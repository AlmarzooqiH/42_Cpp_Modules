/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:14:52 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/27 19:14:52 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    Bureaucrat hamad;
    Bureaucrat larry("Larry", 5);
    Form    roi;
    Form    renewID("ID Renewal", 150, 1);

    std::cout << std::endl;

    hamad.signForm(roi);
    std::cout << std::endl;

    larry.signForm(renewID);
    std::cout << std::endl;

    if (!renewID.getIsSigned())
        hamad.signForm(renewID);
    std::cout << std::endl;
    hamad.signForm(roi);
    return 0;
}
