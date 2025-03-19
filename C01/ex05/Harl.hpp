/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:11:00 by hamad             #+#    #+#             */
/*   Updated: 2025/03/19 19:29:13 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"
#define INVALID "Harl doesn't feel like to complain right now"

    class Harl{

        private:
            void debug(void);
            void info(void);
            void warning(void);
            void error(void);
        
        public:
            void complain(std::string level);
        };
#endif