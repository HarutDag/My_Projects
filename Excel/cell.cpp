#include "cell.h"

    Cell::Cell(const std::string& str)
    {
        name = str;
        color = Color::blue;
    }
    Cell::Cell(const Cell& cl)
    {
        name = cl.name;
        color = cl.color;
    }
    /*Cell::Cell(Cell&& cl)
    {
        name = cl.name;
        color = cl.color;
    }*/
    Cell::Cell()
    {
        name = std::string();
        color = Color::blue;
    }
    Cell::~Cell() { /*std::cout << "\n\nCell destructor\n\n";*/ }
    void Cell::setValue(const std::string& str)
    {
        name = str;
    }
    /*Cell& Cell::operator= (const Cell& cl)
    {
        if (this == &cl)
            return *this;

        name = cl.name;
        color = cl.color;

        return *this;
    }*/
    /*Cell Cell::operator= (Cell&& cl)
    {
        name = cl.name;
        color = cl.color;

        return *this;
    }*/
    std::string Cell::getValue()
    {
        return name;
    }
    int Cell::toInt()
    {
        int val = 0;

        for (int i = 0; name[i] != '\0'; ++i)
        {
            if ('0' <= name[i] && name[i] <= '9')
            {
                val += name[i] - '0';
                val *= 10;
            }
            else if (name[i] == '.')
            {
                val = this->toDouble();
                return val;
            }
            else
            {
                std::cout << "Not a number\n";
                throw;
            }
        }

        return val / 10;
    }
    double Cell::toDouble()
    {
        double val = 0;
        double val2 = 0;

        int i = 0;
        for (; name[i] != '.'; ++i)
        {
            if ('0' <= name[i] && name[i] <= '9')
            {
                val += name[i] - '0';
                val *= 10;
            }
            else
            {
                std::cout << "Not a number\n";
                throw;
            }
        }

        for (int j = i + 1, ten = 10; name[j] != '\0'; ++j, ten *= 10)
        {
            if ('0' <= name[j] && name[j] <= '9')
            {
                val2 += (double)(name[j] - '0') / ten;
            }
            else
            {
                std::cout << "Not a number\n";
                throw;
            }
        }

        return (val / 10) + val2;
    }
    Date Cell::toDate()
    {
        int day = 0;
        bool fKet = false;
        int month = 0;
        bool lKet = false;
        int year = 0;

        int ten = 1;

        for (int i = 0; name[i] != '\0'; ++i)
        {
            if ('0' <= name[i] && name[i] <= '9' && !fKet && !lKet)
            {
                day += name[i] - '0';
                day *= 10;
            }
            else if ('0' <= name[i] && name[i] <= '9' && !lKet)
            {
                month += name[i] - '0';
                month *= 10;
            }
            else if ('0' <= name[i] && name[i] <= '9')
            {
                year += name[i] - '0';
                year *= 10;
            }
            else if (name[i] == '.' && !fKet)
            {
                fKet = true;
                ten = 1;
            }
            else if (name[i] == '.' && !lKet)
            {
                lKet = true;
                ten = 1;
            }
            else
            {
                std::cout << "Not a date\n";
                throw;
            }
        }

        return Date(day / 10, month / 10, year / 10);
    }
    void Cell::reset()
    {
        name = "";
        color = Color::blue;
    }
    void Cell::setColor(char color)
    {
        switch (color)
        {
        case 'r': this->color = Color::red;
            break;
        case 'g': this->color = Color::green;
            break;
        case 'b': this->color = Color::blue;
            break;
        default:
            std::cout << "Color not found\n";
        }
    }
    Color Cell::getColor()
    {
        return color;
    }