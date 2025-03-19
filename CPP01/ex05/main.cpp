/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:09:51 by hamad             #+#    #+#             */
/*   Updated: 2025/03/19 19:32:08 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl hamad;

    hamad.complain(DEBUG);
    hamad.complain(INFO);
    hamad.complain(WARNING);
    hamad.complain(ERROR);
    hamad.complain("This is not a valid level of complaining");
    hamad.complain("This too isn't a valid level of complaining");
    return (0);
}
