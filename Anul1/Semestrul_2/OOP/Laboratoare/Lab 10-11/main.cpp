#include <QtWidgets/QApplication>
#include <qwidget.h>
#include "GUI.h"
#include "teste.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ProductGui gui;
    gui.show();
    //rulare_teste();

    return a.exec();
}
