/*
** EPITECH PROJECT, 2021
** gomoku
** File description:
** gomoku com protocol
*/

#include "com_protocol.hpp"

//com_manager

com_manager::com_manager(brain* used_brain)
    : m_brain(used_brain)
{
    m_board = std::vector<std::vector<int>>();
    wait_board = false;
    is_init = false;

    //timeout_turn;
    //timeout_match;
    //max_memory;
    //time_left;
    //game_type;
    //rule;
    //evaluate;
    folder = ".\\Logs.txt";
}

com_manager::~com_manager()
{}

//com_manager PUBLIC METHODS

void com_manager::read_com(std::string line)
{
    //write_logs(">> READ_COM received line=\"" + line + "\".");

    std::string key = "";
    std::string value = "";
    int delim = 0;
    int size = 0;
    int x = 0;
    int y = 0;

    if (line.find("START ") != std::string::npos) {
        size = std::stoi(line.substr(6), NULL, 10);
        start(size);
    } else if (line.find("TURN ") != std::string::npos) {
        delim = (int) line.find(",");
        x = stoi(line.substr(5, delim), NULL, 10);
        y = stoi(line.substr(delim + 1), NULL, 10);
        turn(x, y);
    } else if (line.find("BEGIN") != std::string::npos) {
        begin();
    } else if (line.find("BOARD") != std::string::npos) {
        wait_board = true;
    } else if (line.find("INFO ") != std::string::npos) {
        delim = (int) line.find(" ", 5);
        key = line.substr(5, delim - 5);
        value = line.substr(delim);
        info(key, value);
    } else if (line.find("END") != std::string::npos) {
        end();
    } else if (line.find("ABOUT") != std::string::npos) {
        about();
    } else {
        unknown("no command corresponding to: \"" + line + "\"");
    }
}

void com_manager::board(std::vector<std::string> v_board)
{
    //write_logs("> BOARD called.");

    size_t size = v_board.size();
    size_t i = 0;
    size_t delim1 = 0;
    size_t delim2 = 0;
    int x = 0;
    int y = 0;
    int value = 0;

    if (is_init == false) {
        error("board wasn't initialized");
        return;
    }

    while (i < size) {
        delim1 = v_board[i].find(",", 0);
        delim2 = v_board[i].find(",", delim1 + 1);
        x = stoi(v_board[i].substr(0, delim1), NULL, 10);
        y = stoi(v_board[i].substr(delim1 + 1, delim2 - delim1), NULL, 10);
        value = stoi(v_board[i].substr(delim2 + 1), NULL, 10);
        m_board[y][x] = value;
        //std::cerr << "x=" << x << ", y=" << y << ", value=" << value << "\n"; //DEBUG
        i++;
    }

    std::stringstream ss;
    for (size_t i = 0; i < m_board.size(); i++) { 
        for (size_t j = 0; j < m_board[i].size(); j++) 
            ss << m_board[i][j] << " "; 
        ss << std::endl;
    }
    //write_logs(ss.str());
    begin();
}

//com_manager PRIVATE METHODS

//RECEIVE

void com_manager::start(int size)
{
    //write_logs("> START called.");

    m_board.clear();

    if (size <= 0) {
        is_init = false;
        error("size can't be zero");
        return;
    }

    is_init = true;

    int i = 0;
    while (i < size) {
        m_board.push_back(std::vector<int>(size, 0));
        i++;
    }
    std::cout << "OK" << std::endl;
}

void com_manager::turn(int x, int y)
{
    //write_logs("> TURN called with x=" + std::to_string(x) + " y=" + std::to_string(y) + ".");
    //message("logfile =" + folder);

    if (is_init == false) {
        error("board wasn't initialized");
        return;
    }
    m_board[y][x] = 2;
    std::vector<size_t> b_move = m_brain->move(m_board, x, y);
    if (b_move.size() < 2) {
        error("brain failed to find move");
        return;
    }
    m_board[(int) b_move[1]][(int) b_move[0]] = 1;
    std::cout << b_move[0] << "," << b_move[1] << std::endl;

    //message("TURN answered with x=" + std::to_string(b_move[0]) + " y=" + std::to_string(b_move[1]) + ".");
}

void com_manager::begin()
{
    //write_logs("> BEGIN called.");

    if (is_init == false) {
        error("board wasn't initialized");
        return;
    }
    std::vector<size_t> b_move = m_brain->move(m_board, -1, -1);
    if (b_move.size() < 2) {
        error("brain failed to find move");
        return;
    }
    m_board[(int) b_move[1]][(int) b_move[0]] = 1;
    std::cout << b_move[0] << "," << b_move[1] << std::endl;

    //message("BEGIN answered with x=" + std::to_string(b_move[0]) + " y=" + std::to_string(b_move[1]) + ".");
}

void com_manager::info(std::string key, std::string value)
{
    //write_logs("> INFO called with key=" + key + " value=" + value + ".");

    if (key == "folder") {
        folder = value + "\\Logs.txt";
        //message("folder = " + value);
    }
}

void com_manager::end()
{
    //write_logs("> END called.\n");

    exit(EXIT_SUCCESS);
}

void com_manager::about()
{
    //write_logs("> ABOUT called.");

    std::cout << "name=\"" << m_brain->name << "\", version=\"" << m_brain->version << "\", author=\"" << m_brain->author << "\", country=\"" << m_brain->country << "\"\n";
}

//SEND

void com_manager::unknown(std::string msg)
{
    //write_logs("> UNKNOWN called with msg=" + msg + ".");

    std::cout << "UNKNOWN " << msg << "\n";
}

void com_manager::error(std::string msg)
{
    //write_logs("> ERROR called with msg=" + msg + ".");

    std::cout << "ERROR " << msg << "\n";
}

void com_manager::message(std::string msg)
{
    //write_logs("> MESSAGE called with msg=" + msg + ".");

    std::cout << "MESSAGE " << msg << "\n";
}

void com_manager::debug(std::string msg)
{
    //write_logs("> DEBUG called with msg=" + msg + ".");

    std::cout << "DEBUG " << msg << "\n";
}

void com_manager::suggest(int x, int y)
{
    //write_logs("> SUGGEST called with x=" + std::to_string(x) + " y=" + std::to_string(x) + ".");

    std::cout << "SUGGEST " << x << "," << y << "\n";
}
