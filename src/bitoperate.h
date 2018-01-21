#ifndef BITOPERATE_H
#define BITOPERATE_H

#include <QWidget>
class QPushButton;

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

private:
    quint64 int_num;
    QPushButton * btn_clear;
    QPushButton * btn_reverse;
};

#endif // BITOPERATE_H
