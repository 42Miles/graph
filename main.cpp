#include "graphwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphWin g;
    g.show();
    return a.exec();
}
