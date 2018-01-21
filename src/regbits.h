#ifndef REGBITS_H
#define REGBITS_H

#include <QWidget>
#include "intbits.h"
#include "lineedits.h"
#include "bitoperate.h"

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
signals:
public slots:
    void set_main_int(quint64 input_int);
};

#endif // REGBITS_H
