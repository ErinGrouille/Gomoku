/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** masks func
*/

#include "masks.hpp"

mask::mask(std::vector<std::vector<int>> m, bool d, int p)
    : mask_0(m), diag(d), prio(p)
{
    if (d == false) {
        mask_1 = std::vector<std::vector<int>>();
        for (size_t i = 0; i < mask_0[0].size(); i++) {
            mask_1.push_back({mask_0[0][i]});
        }
        mask_2 = std::vector<std::vector<int>>(mask_0);
        reverse(mask_2[0].begin(), mask_2[0].end());
        mask_3 = std::vector<std::vector<int>>(mask_1);
        reverse(mask_3.begin(), mask_3.end());
    } else {
        mask_1 = std::vector<std::vector<int>>();
        for (int i = (int)(mask_0[0].size() - 1); i >= 0; i--) {
            mask_1.push_back({mask_0[0][i]});
        }
        for (size_t j = 1; j < mask_0.size(); j++) {
            for (size_t i = 0; i < mask_0[j].size() || i < mask_1.size(); i++) {
                mask_1[i].push_back(mask_0[j][(mask_0[j].size() - 1 - i)]);
            }
        }
        mask_2 = std::vector<std::vector<int>>(mask_0);
        reverse(mask_2.begin(), mask_2.end());
        for (size_t i = 0; i < mask_2.size(); i++) {
            reverse(mask_2[i].begin(), mask_2[i].end());
        }
        mask_3 = std::vector<std::vector<int>>(mask_1);
        reverse(mask_3.begin(), mask_3.end());
        for (size_t i = 0; i < mask_3.size(); i++) {
            reverse(mask_3[i].begin(), mask_3[i].end());
        }
    }
}

mask::~mask()
{}

void print_one_mask(std::vector<std::vector<int>> _mask)
{
    for (size_t j = 0; j < _mask.size(); j++) {
        std::cout << "[";
        for (size_t i = 0; i < _mask[j].size(); i++) {
            std::cout << _mask[j][i];
            if (i < _mask[j].size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void mask::print_self()
{
    std::cout << "Mask of prio " << prio;
    if (diag)
        std::cout << ", type diag:" << std::endl;
    else
        std::cout << ", type line:" << std::endl;

    std::cout << "MASK_0" << std::endl;
    print_one_mask(mask_0);
    std::cout << "MASK_1" << std::endl;
    print_one_mask(mask_1);
    std::cout << "MASK_2" << std::endl;
    print_one_mask(mask_2);
    std::cout << "MASK_3" << std::endl;
    print_one_mask(mask_3);
    std::cout << std::endl;
}

std::vector<mask> init_masks()
{
    std::vector<mask> masks = std::vector<mask>();
    std::vector<std::vector<int>> m;

    //prio 10
    m = {{0, 1, 1, 1, 1}};
    masks.push_back(mask(m, false, 10));
    m = {{0,-1,-1,-1,-1}, {-1,1,-1,-1,-1}, {-1,-1,1,-1,-1}, {-1,-1,-1,1,-1}, {-1,-1,-1,-1,1}};
    masks.push_back(mask(m, true, 10));
    
    m = {{1, 1, 0, 1, 1}};
    masks.push_back(mask(m, false, 10));
    m = {{1,-1,-1,-1,-1}, {-1,1,-1,-1,-1}, {-1,-1,0,-1,-1}, {-1,-1,-1,1,-1}, {-1,-1,-1,-1,1}};
    masks.push_back(mask(m, true, 10));

    m = {{1, 1, 1, 0, 1}};
    masks.push_back(mask(m, false, 10));
    m = {{1,-1,-1,-1,-1}, {-1,1,-1,-1,-1}, {-1,-1,1,-1,-1}, {-1,-1,-1,0,-1}, {-1,-1,-1,-1,1}};
    masks.push_back(mask(m, true, 10));

    //prio 9
    m = {{0, 2, 2, 2, 2}};
    masks.push_back(mask(m, false, 9));
    m = {{0,-1,-1,-1,-1}, {-1,2,-1,-1,-1}, {-1,-1,2,-1,-1}, {-1,-1,-1,2,-1}, {-1,-1,-1,-1,2}};
    masks.push_back(mask(m, true, 9));

    m = {{2, 2, 0, 2, 2}};
    masks.push_back(mask(m, false, 9));
    m = {{2,-1,-1,-1,-1}, {-1,2,-1,-1,-1}, {-1,-1,0,-1,-1}, {-1,-1,-1,2,-1}, {-1,-1,-1,-1,2}};
    masks.push_back(mask(m, true, 9));

    m = {{2, 2, 2, 0, 2}};
    masks.push_back(mask(m, false, 9));
    m = {{2,-1,-1,-1,-1}, {-1,2,-1,-1,-1}, {-1,-1,2,-1,-1}, {-1,-1,-1,0,-1}, {-1,-1,-1,-1,2}};
    masks.push_back(mask(m, true, 9));

    //prio 8
    m = {{0, 1, 1, 1, 0}};
    masks.push_back(mask(m, false, 8));
    m = {{0,-1,-1,-1,-1}, {-1,1,-1,-1,-1}, {-1,-1,1,-1,-1}, {-1,-1,-1,1,-1}, {-1,-1,-1,-1,0}};
    masks.push_back(mask(m, true, 8));

    m = {{0, 1, 0, 1, 1, 0}};
    masks.push_back(mask(m, false, 8));
    m = {{0,-1,-1,-1,-1,-1}, {-1,1,-1,-1,-1,-1}, {-1,-1,0,-1,-1,-1}, {-1,-1,-1,1,-1,-1}, {-1,-1,-1,-1,1,-1}, {-1,-1,-1,-1,-1,0}};
    masks.push_back(mask(m, true, 8));

    //prio 7
    m = {{0, 2, 2, 2, 0}};
    masks.push_back(mask(m, false, 7));
    m = {{0,-1,-1,-1,-1}, {-1,2,-1,-1,-1}, {-1,-1,2,-1,-1}, {-1,-1,-1,2,-1}, {-1,-1,-1,-1,0}};
    masks.push_back(mask(m, true, 7));

    m = {{2, 2, 0, 0, 2}};
    masks.push_back(mask(m, false, 7));
    m = {{2,-1,-1,-1,-1}, {-1,2,-1,-1,-1}, {-1,-1,0,-1,-1}, {-1,-1,-1,0,-1}, {-1,-1,-1,-1,2}};
    masks.push_back(mask(m, true, 7));

    m = {{2, 0, 2, 2}};
    masks.push_back(mask(m, false, 7));
    m = {{2,-1,-1,-1}, {-1,0,-1,-1}, {-1,-1,2,-1}, {-1,-1,-1,2}};
    masks.push_back(mask(m, true, 7));
    
    //prio 7 not square
    m = {{2,-1,-1,-1,2}, {-1,2,-1,2,-1}, {-1,-1,0,-1,-1}};
    masks.push_back(mask(m, true, 7));

    //prio 6
    m = {{2, 0, 2}};
    masks.push_back(mask(m, false, 6));
    m = {{2,-1,-1}, {-1,0,-1}, {-1,-1,2}};
    masks.push_back(mask(m, true, 6));

    m = {{2, 2, 0}};
    masks.push_back(mask(m, false, 6));
    m = {{2,-1,-1}, {-1,2,-1}, {-1,-1,0}};
    masks.push_back(mask(m, true, 6));

    m = {{0,-1,-1,2,2}, {-1,-1,-1,-1,-1}, {-1,-1,-1,-1,-1}, {2,-1,-1,-1,-1}, {2,-1,-1,-1,-1}};
    masks.push_back(mask(m, true, 6));

    m = {{0,-1,2,2}, {-1,-1,-1,-1}, {2,-1,-1,-1}, {2,-1,-1,-1}};
    masks.push_back(mask(m, true, 6));

    //ultra low
    m = {{2,-1}, {-1,0}};
    masks.push_back(mask(m, true, 2));

    m = {{1,-1}, {-1,0}};
    masks.push_back(mask(m, true, 1));

    m = {{1, 0}};
    masks.push_back(mask(m, false, 1));

    m = {{2, 0}};
    masks.push_back(mask(m, false, 1));

    return masks;
}
