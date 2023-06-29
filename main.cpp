#include "Sudoku.h"
#include "StartWindow.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow startWindow;
    startWindow.show();
    return a.exec();
}
