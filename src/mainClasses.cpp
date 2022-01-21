#include <iostream>
#include <string>

const int xxxx = *((int*)"xxxx");
const int yyyy = *((int*)"yyyy");

class Game {
    private:
        int rows[4], columns[4];
        int diag_00_33, diag_03_30;
        int vacant;
        char outcome;
        bool xToMove;
        std::string playerX;
        std::string playerY;
    public:
        Game();
        std::string getPlayerToMove();
        void setPlayerX(std::string name);
        void setPlayerY(std::string name);
        void put(int row, int column);
        char getOutcome();
        void print();
};
Game::Game() {
    diag_00_33 = diag_03_30
               = rows[0] = rows[1] = rows[2] = rows[3]
               = columns[0] = columns[1] = columns[2] = columns[3]
               = *(int*)"----";
    vacant = 16;
    outcome = '-';
    xToMove = true;
    playerX = "Player X";
    playerY = "Player Y";
}
std::string Game::getPlayerToMove() {
    return xToMove ? playerX : playerY;
}
void Game::setPlayerX(std::string name) {
    playerX = name;
}
void Game::setPlayerY(std::string name) {
    playerY = name;
}
void Game::put(int row, int column) {
    if (outcome == '-' and row >= 0 and row < 4 and column >= 0 and column < 4) {
        if (((char*)(&(rows[row])))[column] == '-') {
            ((char*)(&(rows[row])))[column] = ((char*)(&(columns[column])))[row]
                                            = xToMove ? 'x' : 'y';
            if (row == column) {
                ((char*)&diag_00_33)[row] = xToMove ? 'x' : 'y';
            }
            if (row + column == 3) {
                ((char*)&diag_03_30)[row] = xToMove ? 'x' : 'y';
            }
            xToMove = not xToMove;
            vacant--;
            
            // update outcome
            for (int i = 0; i < 4; i++) {
                if (rows[i] == xxxx or columns[i] == xxxx) {
                    outcome = 'x';
                    return;
                }
                if (rows[i] == yyyy or columns[i] == yyyy) {
                    outcome = 'y';
                    return;
                }
            }
            if (diag_00_33 == xxxx or diag_03_30 == xxxx) {
                outcome = 'x';
                return;
            }
            if (diag_00_33 == yyyy or diag_03_30 == yyyy) {
                outcome = 'y';
                return;
            }
            if (vacant == 0) {
                outcome = 'd';
                return;
            }
            outcome = '-';
            return;
        }
    }
}
char Game::getOutcome() {
    return outcome;
}
void Game::print() {
    std::cout<<"\nGame between "<<playerX<<" and "<<playerY<<":\n";
    for (int row = 0; row < 4; row++) {
        std::cout<<'\t';
        for (int i = 0; i < 4; i++) {
            std::cout<<((char*)&(rows[row]))[i];
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}
