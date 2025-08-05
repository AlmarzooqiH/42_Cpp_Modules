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

    hamad.signForm(roi);
    larry.signForm(renewID);

    if (!renewID.getIsSigned())
        hamad.signForm(renewID);

    hamad.signForm(roi);
    return 0;
}
