#ifndef REGBITS_H
#define REGBITS_H

#include <QWidget>
#include "intbits.h"
#include "lineedits.h"
#include "bitoperate.h"

/* Add always_on_top checkbox for windows, this is not nessary for Linux,
 * most Window Manager can do this job well.
*/
#ifdef Q_OS_WIN32
    class QCheckBox;
#endif

#define REG_BIT_NUM 64

class Regbits : public QWidget
{
    Q_OBJECT

public:
    Regbits(QWidget *parent = 0);
    ~Regbits();
private:
    Intbits * intbits;
    LineEdits * lineedits;
    BitOperate * bit_operate;
    quint64  main_int;

#ifdef Q_OS_WIN32
    QCheckBox * ckbox_always_on_top;
public slots:
    void set_alway_on_top(int);
#endif

signals:
public slots:
    void set_main_int(quint64 input_int);

};

#endif // REGBITS_H
