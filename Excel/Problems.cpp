#include "spreedsheet.h"

/* MS Excel:
*  
* .h -eri mej grel amen inchi haytararum-y. Hamapatasxan .cpp -nerum, irakanacumnery.
* 
* Iranic nerkayacnuma axyusyak ( Spreedsheet ( Cell -eri agregat ) ) baxkacac Cell -eric ( X*X -i vra ).
* Stexcelu enq erkchap zangvac Cell[rows][columns] tipi cells.
* Client -y karox e tvyal ( text ( incapsulation -num e std::string ) ) nermucel.
* 
* Client -y karox e stexcel Spreedshet: gri Spreedshet sh = new Spreedsheet (4, 8).
* 
* Spreedshet -n uni ctor (int rows, int cols)
* {
*     Cell** m_cells = new Cell [rows][cols] // rows -eri arajin cell -ery karox en linel anunner. Amenaarajin row -um
*  karox en pahvel amen column -i imasty.
* 
* public:
*     
*     void setCellAt ( int row, int col, Cell cl ) { ... } 
*     void setCellAt ( int row, int col, std::string cl ) { ... }
*     Cell setCellAt ( int row, int col ) { return m_cells[row][col] }
*     void getCellAt ( int row, int col, std::string name ) { ... }
*     void addRow ( int row ) {} // daje mejtexum ( trvac arjeqi row -ic, kam col -ic heto ) petqa karanas avelacnes, pakasacnes
*     void removeRow ( int row ) {}
*     void addColumn ( int col ) {}
*     void remove Column () {}
*     swap Rows ( int row1, int row2 ) {}
*     swap Columns ( int col1, int col2 ) {}
*     
* }
* 
* Client -y ashxateluya menak Spreedsheet -i het, ev ayd kerp e dostup unenalu Cell -erin.
* 
* class Cell
* {
*     std::string name;
*     enum class Color : std::string { , , , };
* public:
*     Cell (std::string str) { ... }
*     void setValue (std::string str) { ... }
*     std::string getValue () { ... }
*     int toInt () {}
*     double to double () {}
*     Date toDate () { return Date } // class Date { int year; ... };
*     void reset () {  }
*     setColor() ...
*     getColor() ...
* };
* 
* Cell -in karox enq poxancel tiv string -i mijocov ( da hamarvum e raw file, ev ayd string -y get
* aneluc petq e veradardzvi int tipi tiv ).
* 
* 
* 
* Code -y stugelu hamar harmar e ogtvel naxapes grvac test -ic ( Test-Driven Development ).
* Cankali e ogtvel tarber mardkanc koxmic grvac test -er nuyn code -i hamar.
* 
* Arajadranq:
* 
* 1. Irakanacnel datark, datark function -nerov, Cell ev Spreedsheetcell class -nery.
*    Ays procesin asum en, vor grum en shell ( makeresayin ) version -y.
* 
* 2. Irakanacnel bolor method -neri kam function -neri test anox file -ery.
* 
* 3. Irakanacnel Cell ev Spreedsheet class -nern amboxjutyamb.
* 
* 4. Kanchelov test function -nery ev hamozvel, vor ashxatum e.
*/

std::string shrjox(std::string str)
{
    for (int i = 0; i < str.size() / 2; ++i)
    {
        str[i] += str[str.size() - 1 - i];
        str[str.size() - 1 - i] = str[i] - str[str.size() - 1 - i];
        str[i] = str[i] - str[str.size() - 1 - i];
    }

    return str;
}

std::string intToString(int val)
{
    std::string str;

    while (val)
    {
        str.push_back('0' + val % 10);
        val /= 10;
    }

    return shrjox(str);
}

int main()
{
    /*
    Spreedsheet(); +
    Spreedsheet(int rows, int cols); +
    ~Spreedsheet(); +
    void setCellAt(int row, int col, const std::string& str); +
    void setCellAt(int row, int col, const Cell& cl); +
    Cell getCellAt(int row, int col); +
    void addRow(int row); +
    void removeRow(int row); +
    void addColumn(int col); +
    void removeColumn(int col); +
    void swapRows(int row1, int row2); +
    void swapColumns(int col1, int col2); +
    */

    Spreedsheet sp;

    int num = 100;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            sp.setCellAt(i, j, intToString(num) + ".15");
            ++num;
        }

    std::cout << "Spreedsheet object -i arjeqnenrn en: \n\n";
    sp.print();


    // add/remove row
    std::cout << "\n\n3 * 2 arjeqy = " << sp.getCellAt(2, 1).getValue() << " -i\n\n";

    sp.addRow(2);
    std::cout << "addRow(2) -ic heto 3 * 2 arjeqy havasarvec - " << sp.getCellAt(2, 1).getValue() << " -i\n\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();

    sp.removeRow(2);
    std::cout << "\nremoveRow(2) -ic heto 3 * 2 arjeqy havasarvec - " << sp.getCellAt(2, 1).getValue() << " -i\n\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();


    // add/remove column
    std::cout << "\n\n2 * 3 arjeqy = " << sp.getCellAt(1, 2).getValue() << " -i\n";

    sp.addColumn(2);
    std::cout << "addColumn(2) -ic heto 2 * 3 arjeqy havasarvec - " << sp.getCellAt(1, 2).getValue() << " -i\n\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();

    sp.removeColumn(2);
    std::cout << "\nremoveColumn(2)-ic heto 2 * 3 arjeqy havasarvec - " << sp.getCellAt(1, 2).getValue() << " -i\n\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();


    // swap rows
    std::cout << "\n\n1 * 4 ev 4 * 4 arjeqynery hamapatasxanabar havasar en " << sp.getCellAt(0, 3).getValue() << " -i ev " << sp.getCellAt(3, 3).getValue() << " -i\n";

    sp.swapRows(1, 4);
    std::cout << "swapRows(1, 4) -ic heto 1 * 4 ev 4 * 4 arjeqynery hamapatasxanabar havasarvecin - " << sp.getCellAt(0, 3).getValue() << " -i ev " << sp.getCellAt(3, 3).getValue() << " -i\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();


    // swap columns
    std::cout << "\n\n1 * 4 ev 4 * 4 arjeqynery hamapatasxanabar havasar en " << sp.getCellAt(0, 3).getValue() << " -i ev " << sp.getCellAt(3, 3).getValue() << " -i\n";

    sp.swapColumns(1, 4);
    std::cout << "sp.swapColumns(1, 4) -ic heto hamapatasxanabar havasarvecin " << sp.getCellAt(0, 3).getValue() << " -i ev " << sp.getCellAt(3, 3).getValue() << " -i\n\n";

    std::cout << "Spreedsheet object -i arjeqnenry dardzan: \n\n";
    sp.print();


    /*
    Cell(const std::string& str); +
    Cell(); +
    void setValue(const std::string& str); +
    std::string getValue(); +
    int toInt(); +
    double toDouble(); +
    Date toDate(); +
    void reset(); +
    void setColor(char color); +
    Color getColor(); +
    */

    std::cout << "\n\nsp.getCellAt(3, 3).toInt() = " << sp.getCellAt(3, 3).toInt() << "\n";
    std::cout << "sp.getCellAt(3, 3).toDouble() = " << sp.getCellAt(3, 3).toDouble() << "\n";
    std::cout << "sp.getCellAt(3, 3).setValue('10.02.2023')\n";
    sp.getCellAt(3, 3).setValue("10.02.2023");
    std::cout << "sp.getCellAt(3, 3).toDate() = ";
    sp.getCellAt(3, 3).toDate().print();
    sp.getCellAt(3, 3).reset();
    std::cout << "sp.getCellAt(3, 3).reset() => " << sp.getCellAt(3, 3).getValue() << '\n';


    std::cout << "\n\n";

    return 0;
}