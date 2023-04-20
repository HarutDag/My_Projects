#pragma once
#include "cell.h"

class Spreedsheet
{
    Cell** m_cells;
    int rows;
    int cols;

public:

    Spreedsheet();
    Spreedsheet(int rows, int cols);
    ~Spreedsheet();
    void setCellAt(int row, int col, const std::string& str);
    void setCellAt(int row, int col, const Cell& cl);
    Cell& getCellAt(int row, int col);
    void addRow(int row);
    void removeRow(int row);
    void addColumn(int col);
    void removeColumn(int col);
    void swapRows(int row1, int row2);
    void swapColumns(int col1, int col2);
    void print();
};