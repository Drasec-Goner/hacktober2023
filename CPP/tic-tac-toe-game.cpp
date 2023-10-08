//Code for "TIC-TAC-TOE"  Game
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

// Function to draw the tic-tac-toe board
void drawBoard(std::vector<char> board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

// Function to check if the game is over
bool isGameOver(std::vector<char> board) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != ' ' && board[i] == board[i+1] && board[i+1] == board[i+2]) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] != ' ' && board[i] == board[i+3] && board[i+3] == board[i+6]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) {
        return true;
    }

    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) {
        return true;
    }

    // Check for tie
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }

    return true;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    std::cout << "Welcome to Tic-Tac-Toe Game!" << std::endl;

    int playerChoice, computerChoice;
    char playerSymbol, computerSymbol;
    std::vector<char> board(9, ' ');
    bool playerTurn = true;

    // Prompt the player for their symbol
    do {
        std::cout << "Do you want to play as X or O? ";
        std::cin >> playerSymbol;
        playerSymbol = toupper(playerSymbol);
    } while (playerSymbol != 'X' && playerSymbol != 'O');

    computerSymbol = (playerSymbol == 'X') ? 'O' : 'X';

    // Game loop
    while (!isGameOver(board)) {
        if (playerTurn) {
            // Player's turn
            drawBoard(board);
            std::cout << "Enter your move (1-9): ";
            std::cin >> playerChoice;

            while (board[playerChoice-1] != ' ') {
                std::cout << "Invalid move. Enter your move again (1-9): ";
                std::cin >> playerChoice;
            }

            board[playerChoice-1] = playerSymbol;
            playerTurn = false;
        } else {
            // Computer's turn
            drawBoard(board);

            std::this_thread::sleep_for(1s); // Add a delay to simulate thinking time

            computerChoice = rand() % 9;

            while (board[computerChoice] != ' ') {
                computerChoice = rand() % 9;
            }

            board[computerChoice] = computerSymbol;
            playerTurn = true;
        }
    }

    // Game over
    drawBoard(board);

    if (isGameOver(board)) {
        if (playerTurn) {
            std::cout << "You win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        }
    } else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
