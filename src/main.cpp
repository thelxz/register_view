#include "regbits.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Regbits w;
    w.show();

    return a.exec();
}
