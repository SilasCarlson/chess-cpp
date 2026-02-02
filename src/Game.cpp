#include "Game.h"

#include <iostream>
#include <ostream>

Game::Game() {
    m_is_running = true;
    m_board = Board();
}

void Game::run() {
    std::string user_input;
    while (m_is_running) {
        // draw the board
        std::cout << "Displaying Board " << m_board.get_width() << "x" << m_board.get_height() << std::endl;
        m_board.draw();

        // get user input
        std::cout << "Would you like to continue (y/n)?" << std::endl;
        std::cin >> user_input;

        // if input is quit then quit
        if (user_input == "n") {
            std::cout << "Thanks for playing!" << std::endl;
            m_is_running = false;
        }
    }
}