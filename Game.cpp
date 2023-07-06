#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            Board[x][y] = *(new Field());
        }
    }
    steps = 0;
}

// returns true if two numbers in one column are the same, else returns false
bool Game::CheckColumn(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (i != y)
        {
            if (Board[x][i].getNumber() == Board[x][y].getNumber())
            {
                return true;
            }
        }
    }
    return false;
}

// returns true if two numbers in one Row are the same, else returns false
bool Game::CheckRow(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (i != x)
        {
            if (Board[i][y].getNumber() == Board[x][y].getNumber())
            {
                return true;
            }
        }
    }
    return false;
}

// returns true if two numbers in one square are the same, else returns false
bool Game::CheckSquare(int x, int y)
{
    for (int ix = x - (x % 3); ix < (x / 3) * 3 + 3; ix++)
    {
        for (int iy = y - (y % 3); iy < (y / 3) * 3 + 3; iy++)
        {
            if (ix != x && iy != y)
            {
                if (Board[ix][iy].getNumber() == Board[x][y].getNumber())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// checks Field x,y for any kind of Conflicts
bool Game::Check(int x, int y)
{
    return (CheckColumn(x, y) || CheckRow(x, y) || CheckSquare(x, y));
}

bool Game::insert(int x, int y, int number)
{
    if (Board[x][y].getFixed())
    {
        return false;
    }

    Board[x][y].setNumber(number);
    if (Check(x, y))
    {
        Board[x][y].setNumber(0);
        return false;
    }

    return true;
}

bool Game::solve(int x, int y)
{
    if (y == 9)
    {
        return true;
    }
    if (Board[x][y].getNumber() != 0)
    {
        if (solve((x + 1) % 9, y + ((x + 1) / 9)))
        {
            return true;
        }
    }
    for (int number = 1; number < 10; number++)
    {
        if (insert(x, y, number))
        {
            if (solve((x + 1) % 9, y + ((x + 1) / 9)))
            {
                return true;
            }
        }
    }
    return false;
}

void Game::Show()
{
    for (int y = 0; y < 9; y++)
    {
        if (y % 3 == 0)
        {
            std::cout << "---------------------------\n";
        }
        for (int x = 0; x < 9; x++)
        {
            if (x % 3 == 0)
            {
                std::cout << " |";
            }
            std::cout << " " << Board[x][y].getNumber();
        }
        std::cout << " |\n";
    }
    std::cout << "---------------------------\n";
}