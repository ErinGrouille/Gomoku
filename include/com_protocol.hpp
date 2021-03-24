/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** gomoku com protocol header
*/


#ifndef COM_PROTOCOL
#define COM_PROTOCOL

#include "brain.hpp"

class com_manager
{
    public:
        com_manager(brain* used_brain);
        ~com_manager();

        void read_com(std::string line);
        void board(std::vector<std::string> v_board);
        bool wait_board;
        bool is_init;
        std::string folder;

    private:
        //int timeout_turn;
        //int timeout_match;
        //int max_memory;
        //int time_left;
        //int game_type;
        //int rule;
        //int* evaluate;

        void start(int size);
        void turn(int x, int y);
        void begin();
        void info(std::string key, std::string value);
        void end();
        void about();

        void unknown(std::string msg);
        void error(std::string msg);
        void message(std::string msg);
        void debug(std::string msg);
        void suggest(int x, int y);

        std::vector<std::vector<int>> m_board;
        brain *m_brain;
};


#endif /* !COM_PROTOCOL */
