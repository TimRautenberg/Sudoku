#include <iostream>
#include "Game.h"
#include "Field.h"

int main()
{
    Game *Sudoku = new Game();
    Sudoku->insert(0,0,9);
    Sudoku->solve(0, 0);
    Sudoku->Show();
}