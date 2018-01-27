#include "regbits.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Regbits main_win;
    main_win.show();
    main_win.setFixedSize(main_win.width(),main_win.height());

    return a.exec();
}
