#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawBoard(const char *spots);
void playerMove(char *spots, char player);
void computerMove(char *spots, char computer);
bool calculateWinner(char *spots, char player, char computer);
bool calculateTie(const char *spots);

int main()
{
    char spots[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    const char player = 'X';
    const char computer = '0';
    bool running = true;

    drawBoard(spots);

    // The main game loop
    while (running)
    {
        playerMove(spots, player);
        drawBoard(spots);

        // Check if the player has won
        if (calculateWinner(spots, player, computer))
        {
            running = false;
            break;
        }
        // Check if it's a tie
        else if (calculateTie(spots))
        {
            running = false;
            break;
        }

        computerMove(spots, computer);
        drawBoard(spots);

        // Check if the computer has won
        if (calculateWinner(spots, player, computer))
        {
            running = false;
            break;
        }
        // Check if it's a tie
        else if (calculateTie(spots))
        {
            running = false;
            break;
        }
    }

    return 0;
}

// Function to draw the tic-tac-toe board
void drawBoard(const char *spots)
{
    system("cls");
    cout << "\n";
    cout << "     |     |     " << '\n';
    cout << "  " << spots[0] << "  |  " << spots[1] << "  |  " << spots[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spots[3] << "  |  " << spots[4] << "  |  " << spots[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spots[6] << "  |  " << spots[7] << "  |  " << spots[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << "\n";
}

// Function to handle the player's move
void playerMove(char *spots, char player)
{
    bool choiceState = true;
    int choice;

    std::cout << "Enter a slot number (1-9): ";

    // Verifies if the input is a number and is between 1 and 9, and if the spot is empty
    while (!(std::cin >> choice) || std::cin.peek() != '\n' || choice < 1 || choice > 9 || spots[choice - 1] != ' ')
    {
        std::cout << "Invalid input. Please enter a number (1-9): ";

        // Clear the input buffer
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }

    spots[choice - 1] = player;
}

// Function to handle the computer's move
void computerMove(char *spots, char computer)
{
    bool correctChoice = false;
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice = 0 + rand() % (8 - 0 + 1);

    // Choose a random spot for the computer to move
    while (spots[choice] == 'X' || spots[choice] == '0')
    {
        choice = 0 + rand() % (8 - 0 + 1);
    }

    cout << choice << "\n";
    spots[choice] = computer;
}

// Function to check if a player has won
bool calculateWinner(char *spots, char player, char computer)
{
    if ((spots[0] != ' ') && spots[0] == spots[1] && spots[1] == spots[2])
    {
        (spots[0] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[3] != ' ' && spots[3] == spots[4] && spots[4] == spots[5])
    {
        (spots[3] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[6] != ' ' && spots[6] == spots[7] && spots[7] == spots[8])
    {
        (spots[6] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[0] != ' ' && spots[0] == spots[3] && spots[3] == spots[6])
    {
        (spots[0] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[1] != ' ' && spots[1] == spots[4] && spots[4] == spots[7])
    {
        (spots[1] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[2] != ' ' && spots[2] == spots[5] && spots[5] == spots[8])
    {
        (spots[2] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[0] != ' ' && spots[0] == spots[4] && spots[4] == spots[8])
    {
        (spots[0] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else if (spots[2] != ' ' && spots[2] == spots[4] && spots[4] == spots[6])
    {
        (spots[2] == player) ? cout << "PLAYER won." << '\n' : cout << "COMPUTER won." << '\n';
    }
    else
    {
        return false;
    }

    return true;
}

// Function to check if it's a tie
bool calculateTie(const char *spots)
{
    for (int i = 0; i < 9; i++)
    {
        if (spots[i] == ' ')
        {
            return false;
        }
    }

    cout << "It's a TIE!." << '\n';
    return true;
}

