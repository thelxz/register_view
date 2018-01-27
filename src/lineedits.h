#ifndef LINEEDITS_H
#define LINEEDITS_H

#include <QWidget>
class QLineEdit;
class QLabel;
class TxtAddrSize;

class LineEdits : public QWidget
{
    Q_OBJECT
public:
    explicit LineEdits(QWidget *parent = 0);
    void set_value(quint64 input_num);
    quint64 get_value();

private:
    void update_display();
    void update_data(quint64 input_int);
    quint64 int_num;
    QLineEdit * numHex;
    QLineEdit * numDec;
    QLineEdit * numOct;
    QLineEdit * numBin;
    TxtAddrSize * txt_addr_size;
    QLabel * labelHex;
    QLabel * labelDec;
    QLabel * labelOct;
    QLabel * labelBin;
    QLabel * labelAddrsize;

signals:
    void value_changed(quint64 num);
public slots:
    void hex_text_changed(QString str);
    void dec_text_changed(QString str);
    void oct_text_changed(QString str);
    void bin_text_changed(QString str);

};

#endif // LINEEDITS_H
