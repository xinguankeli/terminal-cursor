#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    MyCursor c;
//    c.setFixedSize(3, 20);
//    c.show();

    return a.exec();
}
