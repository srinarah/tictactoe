#include <iostream>
#include <string>

#include "mainClasses.cpp"

void promptForName(char letter, std::string &name);
bool promptForMove(Game g, int &row, int &column);
void runGame(std::string playerX, std::string playerY);

void promptForName(char letter, std::string &name) {
    std::string buffer;
    std::cout<<"Player "<<letter<<", what is your name? \n";

    std::getline(std::cin, buffer);
    if (not buffer.empty()) {
        name = buffer;
    }
}
bool promptForMove(Game g, int &row, int &column) {
    std::cout<<g.getPlayerToMove()<<", ";
    std::cout<<"please enter a row (0 top, 3 bottom) ";
    std::cout<<"and a column (0 leftmost, 3 rightmost), ";
    std::cout<<"separated by a space.\n";

    if (std::cin) {
        std::cin>>row;
        if (std::cin) {
            std::cin>>column;
            return true;
        }
    }
    return false;
}
void runGame(std::string playerX, std::string playerY) {
    Game g;
    char outcome;
    int row, column;

    g.setPlayerX(playerX);
    g.setPlayerY(playerY);

    while ((outcome = g.getOutcome()) == '-') {
        g.print();
        if (promptForMove(g, row, column)) {
            g.put(row, column);
        } else {
            break;
        }
    }
    
    g.print();
    switch (outcome) {
        case '-':
            std::cout<<"Game incomplete. :(\n";
            break;
        case 'd':
            std::cout<<"It is a draw.\n";
            break;
        case 'x':
            std::cout<<playerX<<" wins!\n";
            break;
        case 'y':
            std::cout<<playerY<<" wins!\n";
            break;
    }
}
