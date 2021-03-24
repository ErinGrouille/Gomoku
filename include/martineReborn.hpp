/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** martineReborn header
*/

#ifndef MARTINEREBORN
#define MARTINEREBORN

#include "brain.hpp"
#include "masks.hpp"

class MartineReborn : virtual public brain
{
    public:
        MartineReborn();
        ~MartineReborn();

        std::vector<size_t> move(std::vector<std::vector<int>> board, int x, int y);
        std::string name;
        std::string version;
        std::string author;
        std::string country;

        void print_masks();

    private:
        std::vector<mask> masks;
        std::vector<size_t> default_move(std::vector<std::vector<int>> board);
        int highestPrio(std::vector<std::vector<std::vector<int>>> founds);
        bool checkMask(std::vector<std::vector<int>> board, int i, int j, std::vector<std::vector<int>> _mask);
        std::vector<int> findZeroIJ(std::vector<std::vector<int>>_mask, int offI, int offJ);
        std::vector<int> findMask(std::vector<std::vector<int>> board, mask _mask);


};

#endif /* !MARTINEREBORN */