#include <string>
#include "mainFunctions.cpp"

int main() {
    std::string playerX = "Player X";
    std::string playerO = "Player O";
    
    promptForName('x', playerX);
    promptForName('o', playerO);
    
    runGame(playerX, playerO);

    return 0;
}
