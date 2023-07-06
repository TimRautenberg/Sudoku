#ifndef GAME_H
#define GAME_H

#include "Field.h"

class Game
{
private:
    Field Board[9][9];
    int steps;

    // Checks for Conflict in Row between Field(x,y) and the rest of the Row
    // returns True if there is a Conflict
    bool CheckRow(int x, int y);

    // Checks for Conflict in Column between Field(x,y) and the rest of the Column
    // returns True if there is a Conflict
    bool CheckColumn(int x, int y);

    // Checks for Conflict in Square between Field(x,y) and the rest of the Square
    // returns True if there is a Conflict
    bool CheckSquare(int x, int y);

    // Checks for Conflict in Row, Column and Square between Field(x,y)
    // and the rest of the included Fields
    // returns True if there is a Conflict
    bool Check(int x, int y);

public:
    Game();

    // tries to insert an number at Position (x,y)
    // if there is no Conflict afterwards return true
    // else delete the Field and return false
    bool insert(int x, int y, int number);

    // solves the Sudoku recursivly
    // returns true if it is solved false if its not solvable
    bool solve(int x, int y);

    // prints the current state of the Sudoku to the terminal
    void Show();
};
#endif // GAME_H