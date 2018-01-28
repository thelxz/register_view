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
    //other widgets change the value, just update display
    void update_display();
    //current widgets change the value, would send value_changed signal.
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
    void txt_addr_size_changed(quint64 value);
    void check_empty();

};

#endif // LINEEDITS_H
