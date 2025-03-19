/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:13:12 by hamad             #+#    #+#             */
/*   Updated: 2025/03/18 23:58:14 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon &hWeapon;

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack(void);
};

#endif