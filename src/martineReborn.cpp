/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** martine brain func
*/

#include "martineReborn.hpp"

MartineReborn::MartineReborn()
{
    masks = init_masks();
    name = "MartineReborn";
    version = "1.0";
    author = "E.Grouille & T.Prugnon";
    country = "FR";
}

MartineReborn::~MartineReborn()
{}

void MartineReborn::print_masks()
{
    std::cout << "printing masks..." << std::endl;
    for (size_t i = 0; i < masks.size(); i++) {
        masks[i].print_self();
    }
    std::cout << "all masks printed." << std::endl;
}

std::vector<size_t> MartineReborn::move(std::vector<std::vector<int>> board, int x, int y)
{
    x++;
    y++;

    std::vector<size_t> my_move = std::vector<size_t>();
    std::vector<int> f = std::vector<int>();

    //founds[i] = {{x, y}, {prio}}
    std::vector<std::vector<std::vector<int>>> founds = std::vector<std::vector<std::vector<int>>>();

    for (size_t a = 0; a < masks.size(); a++) {
        f = findMask(board, masks[a]);
        if (f.size() == 2)
            founds.push_back({f, {masks[a].prio}});
    }
    if (founds.size() > 0) {
        int id = highestPrio(founds);
        my_move.push_back(founds[id][0][0]);
        my_move.push_back(founds[id][0][1]);
        return (my_move);
    }
    my_move.clear();
    my_move = default_move(board);
    return my_move;
}

std::vector<size_t> MartineReborn::default_move(std::vector<std::vector<int>> board)
{
    std::vector<size_t> my_move = std::vector<size_t>();
    size_t x = 0;
    size_t y = 0;

    //default filling
    while (y < board.size()) {
        while(x < board[y].size()) {
            if (board[y][x] == 0) {
                my_move.push_back(x);
                my_move.push_back(y);
                return my_move;
            }
            x++;
        }
        x = 0;
        y++;
    }
    return my_move;
}

int MartineReborn::highestPrio(std::vector<std::vector<std::vector<int>>> founds)
{
    int p = 0;
    int id = 0;

    for (int i = 0; i < (int) founds.size(); i++) {
        if (founds[i][1][0] > p) {
            id = i;
            p = founds[i][1][0];
        }
    }
    return id;
}

bool MartineReborn::checkMask(std::vector<std::vector<int>> board, int i, int j, std::vector<std::vector<int>> _mask)
{
	for (size_t k = 0; k < _mask.size(); k++) {
		for (size_t l = 0; l < _mask[k].size(); l++) {
			if (board[i+k][j+l] != _mask[k][l] && _mask[k][l] != -1)
				return false;
        }
    }
	return true;
}

std::vector<int> MartineReborn::findZeroIJ(std::vector<std::vector<int>>_mask, int offI, int offJ)
{
    std::vector<int> zeroPlace = std::vector<int>();
	for (size_t i = 0; i < _mask.size(); i++){
		for (size_t j = 0; j < _mask[i].size(); j++){
			if (_mask[i][j] == 0) {
                zeroPlace.push_back(j+offJ);
                zeroPlace.push_back(i+offI);
                return zeroPlace;
            }
        }
    }
    zeroPlace.clear();
    return zeroPlace;
}

std::vector<int> MartineReborn::findMask(std::vector<std::vector<int>> board, mask _mask)
{
    for (size_t i = 0; i < (board.size() - (_mask.mask_0.size() - 1)); i++) {
		for (size_t j = 0; j < (board[i].size() - _mask.mask_0[0].size()); j++) {
			if (checkMask(board,i,j,_mask.mask_0)) {
				return findZeroIJ(_mask.mask_0, i, j);
            }
        }
    }
    for (size_t i = 0; i < (board.size() - (_mask.mask_1.size() - 1)); i++) {
		for (size_t j = 0; j < (board[i].size() - _mask.mask_1[0].size()); j++) {
			if (checkMask(board,i,j,_mask.mask_1)) {
				return findZeroIJ(_mask.mask_1, i, j);
            }
        }
    }
    for (size_t i = 0; i < (board.size() - (_mask.mask_2.size() - 1)); i++) {
		for (size_t j = 0; j < (board[i].size() - _mask.mask_2[0].size()); j++) {
			if (checkMask(board,i,j,_mask.mask_2)) {
				return findZeroIJ(_mask.mask_2, i, j);
            }
        }
    }
    for (size_t i = 0; i < (board.size() - (_mask.mask_3.size() - 1)); i++) {
		for (size_t j = 0; j < (board[i].size() - _mask.mask_3[0].size()); j++) {
			if (checkMask(board,i,j,_mask.mask_3)) {
				return findZeroIJ(_mask.mask_3, i, j);
            }
        }
    }
    return std::vector<int>();
}