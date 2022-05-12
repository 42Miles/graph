//#include "mainwindow.h"
#include "graphwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    GraphWin g;
    g.show();
    return a.exec();
}
