#include "Game.h"

#include <iostream>
#include <ostream>

Game::Game() {
    m_is_running = true;
    m_board = Board();
}

int Game::get_position_from_letter(char const letter) {
    switch (letter) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default:  return 8;
    }
}

void Game::run() {
    // initialize variables
    std::string initial_position, final_position;

    // main loop
    while (m_is_running) {
        std::cout << "Turn: " << (m_is_white_turn ? "White" : "Black") << std::endl;
        m_board.draw();

        // get user input
        std::cout << "What piece would you like to move (ex. a1)?" << std::endl;
        std::cin >> initial_position;

        std::cout << "Where would you like to move it too (ex. a2)?" << std::endl;
        std::cin >> final_position;

        // process input
        if (initial_position.length() == 2 && final_position.length() == 2) {
            const char letter_initial_position = static_cast<char>(std::tolower(initial_position[0]));
            const char number_initial_position = initial_position[1];

            const char letter_final_positon = static_cast<char>(std::tolower(final_position[0]));
            const char number_final_position = final_position[1];

            // validation check for the initial position and final position
            if (std::isdigit(number_initial_position) && std::isdigit(number_final_position) &&
                get_position_from_letter(letter_initial_position) != 8 && get_position_from_letter(letter_final_positon) != 8) {
                const int initial_x = get_position_from_letter(letter_initial_position);
                const int initial_y = 8 - (number_initial_position - '0');
                const int final_x = get_position_from_letter(letter_final_positon);
                const int final_y = 8 - (number_final_position - '0');

                if (m_board.is_white_piece(initial_x, initial_y) == m_is_white_turn && m_board.move_piece(initial_x, initial_y, final_x, final_y)) {
                    // update whose turn it is
                    m_is_white_turn = !m_is_white_turn;
                }
            }
        }
    }
}
