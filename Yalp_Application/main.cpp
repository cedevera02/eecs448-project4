#include "yalpwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YalpWindow w;
    w.show();
    return a.exec();
}
