/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:24:10 by hamad             #+#    #+#             */
/*   Updated: 2025/03/03 22:27:35 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_isalpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void	ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
		std::cout << (char)(c - 32);
	else
		std::cout << c;
}

int main(int ac, char **av){
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        int j = 0;
        while (av[i][j])
        {
            if (ft_isalpha(av[i][j]))
                ft_toupper(av[i][j]);
            else
                std::cout << av[i][j];
            j++;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
