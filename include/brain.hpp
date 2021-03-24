/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** brain header
*/

#ifndef BRAIN
#define BRAIN

#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class brain
{
    public:
        virtual ~brain(){};

        virtual std::vector<size_t> move(std::vector<std::vector<int>> , int x, int y) = 0;
        std::string name;
        std::string version;
        std::string author;
        std::string country;
};

void write_logs(std::string msg);

#endif /* !BRAIN */
