#ifndef BITOPERATE_H
#define BITOPERATE_H

#include <QWidget>
class QPushButton;
class QCheckBox;
class QLineEdit;

class BitOperate : public QWidget
{
    Q_OBJECT
public:
    explicit BitOperate(QWidget *parent = nullptr);
    void set_value(quint64 input_num);
    quint64 get_value();

signals:
    void value_changed(quint64 num);

public slots:
    void clear_num();
    void reverse_num();
    void set_num();
    void shift_left();
    void shift_right();

private:
    quint64 int_num;
    QPushButton * btn_clear;
    QPushButton * btn_reverse;
    QPushButton * btn_set;
    QPushButton * btn_shift_left;
    QLineEdit 	* txt_shift_bit_num;
    QPushButton * btn_shift_right;
};

#endif // BITOPERATE_H
