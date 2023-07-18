# C++ Console Tic-Tac-Toe Game

## Description

This is a simple implementation of the Tic-Tac-Toe game in C++. The code prompts the user to enter a slot number (1-9) and validates the input before updating the game board.

![ezgif com-video-to-gif (1)](https://github.com/biccsdev/TicTacToe-Cpplus-Console/assets/86041666/3f802e6d-33e9-4aaa-bd41-6678fa907ce4)

## Prerequisites

- C++ compiler (supporting C++11 or later)

## Getting Started

### Installation

Clone the repository or download the source code.

### Usage

1. Compile the code using a C++ compiler.
2. Run the compiled executable.

## Code Explanation

The code provided allows the user to make a move in the Tic-Tac-Toe game. Here's how it works:

1. The variable `choiceState` is initialized to `true`, indicating that the user can make a choice.
2. The variable `choice` is declared to store the user's input.
3. The code displays a prompt: "Enter a slot number (1-9): ".
4. It enters a loop to validate the user's input using several conditions:
   - `!(std::cin >> choice)` checks if the input is not a valid integer.
   - `std::cin.peek() != '\n'` checks if there are extra characters in the input after the number.
   - `choice < 1 || choice > 9` checks if the input is within the range of 1 to 9.
   - `spots[choice - 1] != ' '` checks if the chosen slot is already occupied.
5. If any of the validation conditions fail, an error message is displayed: "Invalid input. Please enter a number (1-9): ".
6. The code then clears the input buffer to remove any remaining characters.
7. Once a valid input is obtained, the code updates the game board by assigning the current player's symbol to the chosen slot.

## License

[MIT](LICENSE)
