/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:06:03 by hamad             #+#    #+#             */
/*   Updated: 2025/03/19 01:37:29 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#define INPUT_ERROR "./change [file_name] [Word you want to change] [The word you will replace it with]"
int main(int ac, char **av)
{
    if (ac == 4)
    {
        for (int i = 1; i < ac; i++)
        {
            if (av[i][0] =='\0' || av[i] == NULL)
            {
                std::cout << "Please provide a valid entry" << std::endl;
                std::cout << INPUT_ERROR << std::endl;
                return (1);
            }
        }
        std::string fileName = av[1];
        std::ifstream filein(fileName.c_str());
        std::ofstream fileout((fileName + ".replace").c_str());
        if (!filein.is_open())
        {
            std::cout << "Couldn't open the file" << std::endl;
            return (1);
        }
        std::string line;
        std::string new_line = "";
        while (std::getline(filein, line)){
            size_t start = 0, end = 0;
            while (end <= line.length())
            {
                if (end == line.length() || line.at(end) == ' ')
                {
                    std::string word = line.substr(start, end - start);
                    if (word == av[2] || word.find(av[2]) == 0)
                        new_line.append(av[3]);
                    else
                        new_line.append(word);
                    
                    if (end < line.length())
                        new_line.append(" ");
                    start = end + 1;
                }
                end++;
            }
            fileout << new_line << std::endl;
            new_line.clear();}
        filein.close();
        fileout.close();

    }else{
        std::cout << INPUT_ERROR << std::endl;
    }
    return 0;
}
