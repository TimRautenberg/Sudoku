#include "Field.h"

Field::Field(int number, bool fixed)
{
    _number = number;
    _fixed = fixed;
}

bool Field::getFixed()
{
    return _fixed;
}

void Field::setFixed(bool value)
{
    _fixed = value;
}

int Field::getNumber()
{
    return _number;
}

void Field::setNumber(int value)
{
    _number = value;
}