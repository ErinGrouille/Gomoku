/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** masks header
*/

#ifndef MASKS
#define MASKS

#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

class mask
{
    public:
        mask(std::vector<std::vector<int>> m, bool d, int p);
        ~mask();
    
        std::vector<std::vector<int>> mask_0;
        std::vector<std::vector<int>> mask_1;
        std::vector<std::vector<int>> mask_2;
        std::vector<std::vector<int>> mask_3;
        bool diag;
        int prio;

        void print_self();
};

std::vector<mask> init_masks();

#endif /* !MASKS */