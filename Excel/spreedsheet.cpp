#include "spreedsheet.h"

    Spreedsheet::Spreedsheet()
    {
        rows = 4;
        cols = 4;
        m_cells = new Cell * [rows];
        for (int i = 0; i < rows; ++i)
            m_cells[i] = new Cell[cols];
    }
    Spreedsheet::Spreedsheet(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        m_cells = new Cell * [rows];
        for (int i = 0; i < rows; ++i)
            m_cells[i] = new Cell[cols];
    }

    Spreedsheet::~Spreedsheet()
    {
        for (int i = 0; i < rows; ++i)
            delete[] m_cells[i];

        delete[] m_cells;
    }
    void Spreedsheet::setCellAt(int row, int col, const std::string& str)
    {
        if (0 > row || row >= rows || 0 > col || col >= cols)
        {
            std::cout << "Poxancvel e sxal hasce!\n";
            throw;
        }

        m_cells[row][col].setValue(str);
    }
    void Spreedsheet::setCellAt(int row, int col, const Cell& cl)
    {
        if (0 > row || row >= rows || 0 > col || col >= cols)
        {
            std::cout << "Poxancvel e sxal hasce!\n";
            throw;
        }

        m_cells[row][col] = cl;
    }
    Cell& Spreedsheet::getCellAt(int row, int col)
    {
        if (0 > row || row >= rows || 0 > col || col >= cols)
        {
            std::cout << "Poxancvel e sxal hasce!\n";
            throw;
        }

        return m_cells[row][col];
    }
    void Spreedsheet::addRow(int row)// daje mejtexum ( trvac arjeqi row -ic, kam col -ic heto ) petqa karanas avelacnes, pakasacnes
    {
        if (0 > row || row > rows)
        {
            std::cout << "Row not found\n";
            return;
        }

        Cell** tmp = new Cell * [rows + 1];
        for (int i = 0, t = 0; i < rows + 1; ++i)
        {
            if (i == row)
            {
                tmp[i] = new Cell[cols];
                ++t;
                continue;
            }
            tmp[i] = m_cells[i - t];
        }
        /*for (int i = 0; i < rows; ++i)
            delete[]m_cells[i];
        delete[] m_cells;*/
        m_cells = tmp;
        tmp = nullptr;

        ++rows;
    }
    void Spreedsheet::removeRow(int row)
    {
        if ( 0 > row || row > rows)
        {
            std::cout << "Row not found\n";
            return;
        }

        Cell** tmp = new Cell * [rows - 1];
        for (int i = 0, t = 0; i < rows; ++i)
        {
            if (i == row)
            {
                ++t;
                delete[] m_cells[i];
                continue;
            }
            tmp[i - t] = m_cells[i];
        }
        /*for (int i = 0; i < rows; ++i)
            delete[] m_cells[i];
        delete[] m_cells;*/
        m_cells = tmp;
        tmp = nullptr;

        --rows;
    }
    void Spreedsheet::addColumn(int col)
    {
        if (0 > col || col > cols)
        {
            std::cout << "Col not found\n";
            return;
        }

        Cell** tmp = new Cell * [rows];
        for (int i = 0; i < rows; ++i)
        {
            tmp[i] = new Cell[cols + 1];
            for (int j = 0, t = 0; j < cols + 1; ++j)
            {
                if (j == col)
                {
                    tmp[i][j].setValue("");
                    ++t;
                    continue;
                }
                tmp[i][j] = m_cells[i][j - t];
            }
        }
        /*for (int i = 0; i < rows; ++i)
            delete[]m_cells[i];
        delete[] m_cells;*/
        m_cells = tmp;
        tmp = nullptr;

        ++cols;
    }
    void Spreedsheet::removeColumn(int col)
    {
        if (0 > col || col > cols)
        {
            std::cout << "Col not found\n";
            return;
        }

        Cell** tmp = new Cell * [rows];
        for (int i = 0; i < rows; ++i)
        {
            tmp[i] = new Cell[cols - 1];
            for (int j = 0, t = 0; j < cols; ++j)
            {
                if (j == col)
                {
                    ++t;
                    continue;
                }
                tmp[i][j - t] = m_cells[i][j];
            }
        }
        /*for (int i = 0; i < rows; ++i)
            delete[]m_cells[i];
        delete[] m_cells;*/
        m_cells = tmp;
        tmp = nullptr;

        --cols;
    }
    void Spreedsheet::swapRows(int row1, int row2)
    {
        if (0 > row1 || row1 > rows || 0 > row2 || row2 > rows)
        {
            std::cout << "Row not found\n";
            return;
        }
        if (row1 == row2)
            return;

        int r1 = 0;
        int r2 = 0;

        if (row1 < row2)
        {
            r1 = row1;
            r2 = row2;
        }
        else
        {
            r1 = row2;
            r2 = row1;
        }

        Cell* tmp = m_cells[r1 - 1];
        m_cells[r1 - 1] = m_cells[r2 - 1];
        m_cells[r2 - 1] = tmp;
        tmp = nullptr;

        /*Cell** tmp = new Cell* [rows];
        for (int i = 0; i < rows; ++i)
        {
            if (i == r1 - 1)
            {
                tmp[i] = m_cells[r2 - 1];
                tmp[r2 - 1] = m_cells[i];
                continue;
            }
            if (i == r2 - 1)
                continue;
            tmp[i] = m_cells[i];
        }
        for (int i = 0; i < rows; ++i)
            delete[]m_cells[i];
        delete[] m_cells;
        m_cells = tmp;
        tmp = nullptr;*/
     }
    void Spreedsheet::swapColumns(int col1, int col2)
    {
        if (0 >= col1 || col1 > cols || 0 >= col2 || col2 > cols)
        {
            std::cout << "Column not found\n";
            return;
        }
        if (col1 == col2)
            return;

        int c1 = 0;
        int c2 = 0;

        if (col1 < col2)
        {
            c1 = col1;
            c2 = col2;
        }
        else
        {
            c1 = col2;
            c2 = col1;
        }

        Cell tmp;
        for (int i = 0; i < rows; ++i)
        {
            tmp = m_cells[i][c1 - 1];
            m_cells[i][c1 - 1] = m_cells[i][c2 - 1];
            m_cells[i][c2 - 1] = tmp;
        }

        /*Cell** tmp = new Cell * [rows];
        *for (int i = 0; i < rows; ++i)
            tmp[i] = new Cell[cols];*

        for (int i = 0; i < rows; ++i)
        {
            tmp[i] = m_cells[i];
            for (int j = 0; j < cols; ++j)
            {
                if (j == c1 - 1)
                {
                    tmp[i][j] = m_cells[i][c2 - 1];
                    tmp[i][c2 - 1] = m_cells[i][j];
                    continue;
                }
                if (j == c2 - 1)
                    continue;
                //tmp[i][j] = m_cells[i][j];
            }
        }
        m_cells = tmp;
        tmp = nullptr;*/
    }

    void Spreedsheet::print()
    {
        for (int i = 0; i < rows; ++i)
        {
            std::cout << '\n';
            for (int j = 0; j < cols; ++j)
            {
                std::cout << m_cells[i][j].getValue() << ' ';
            }
        }
    }