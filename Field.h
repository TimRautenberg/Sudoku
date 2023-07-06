#ifndef FIELD_H
#define FIELD_H

class Field
{
private:
    int _number;
    bool _fixed;

public:
    Field(int number = 0, bool fixed = false);
    int getNumber();
    void setNumber(int value);
    bool getFixed();
    void setFixed(bool value);
};

#endif // FIELD_H