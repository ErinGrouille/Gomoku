/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** gomoku main
*/

#include "com_protocol.hpp"
//#include "martine.hpp"
//#include "martineEvolved.hpp"
#include "martineReborn.hpp"

static std::string* logs_path;

void write_logs(std::string msg)
{
    std::ofstream logFile;
    logFile.exceptions (std::ofstream::failbit);
    try
    {
        logFile.open (*logs_path, std::ios_base::app);
    }
    catch(std::ofstream::failure &e)
    {
        std::cout << "MESSAGE open said=" << e.what() << std::endl;
        return;
    }
    logFile << msg << std::endl;
    logFile.close();
}

int main()
{
    //Martine my_brain = Martine();
    //MartineEvolved my_brain = MartineEvolved();
    MartineReborn my_brain = MartineReborn();
    //my_brain.print_masks();
    com_manager manager = com_manager(&my_brain);
    std::string line = "";
    std::vector<std::string> v_board = std::vector<std::string>();
    logs_path = &manager.folder;

    while(42) {
        line = "";
        std::getline(std::cin, line);
        manager.read_com(line);
        if (manager.wait_board == true) {
            v_board.clear();
            line = "";
            std::getline(std::cin, line);
            while (line.find("DONE") == std::string::npos) {
                v_board.push_back(line);
                line = "";
                std::getline(std::cin, line);
            }
            manager.wait_board = false;
            manager.board(v_board);
        }
    }
    return 0;
}