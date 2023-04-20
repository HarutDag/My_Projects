#pragma once
#include <iostream>

enum class Color : char { red = 'r', green = 'g', blue = 'b' };

class Date
{
    int year;
    int month;
    int day;
public:

    Date()
    {
        day = 777;
        month = 777;
        year = 777;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void print()
    {
        std::cout << day << '.' << month << '.' << year << '\n';
    }
};

class Cell
{
    std::string name;
    Color color;
public:
    Cell(const std::string& str);
    Cell(const Cell& cl);
    //Cell(Cell&& cl);
    Cell();
    ~Cell();
    //Cell& operator= (const Cell& cl);
    //Cell operator= (Cell&& cl);
    void setValue(const std::string& str);
    std::string getValue();
    int toInt();
    double toDouble();
    Date toDate();
    void reset();
    void setColor(char color);
    Color getColor();
};