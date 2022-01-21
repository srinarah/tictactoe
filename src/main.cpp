#include <string>
#include "mainFunctions.cpp"

int main() {
    std::string playerX = "Player X";
    std::string playerY = "Player Y";
    
    promptForName('x', playerX);
    promptForName('y', playerY);
    
    runGame(playerX, playerY);

    return 0;
}
