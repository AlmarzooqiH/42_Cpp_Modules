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


int main(void) {
    Bureaucrat hamad;
    Bureaucrat larry("Larry", 5);
    Form    roi;
    Form    renewID("ID Renewal", 150, 1);

    std::cout << "================= Bureaucrats ==========================" << std::endl;
    std::cout << hamad << std::endl << larry << std::endl;
    std::cout << "=================     Forms   ==========================" << std::endl;
    std::cout << roi << std::endl << renewID << std::endl;
    std::cout << "================= Larry will try to sign the forms =============" << std::endl;
    larry.signForm(roi);
    larry.signForm(renewID);
    std::cout << "================= Hamad will try to sign the forms =============" << std::endl; 
    hamad.signForm(roi);
    hamad.signForm(renewID);
    std::cout << "================= Program end ==================================" << std::endl; 
    return (0);
}
