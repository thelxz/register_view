#ifndef TXTADDRSIZE_H
#define TXTADDRSIZE_H
#include <QLineEdit>


class TxtAddrSize : public QLineEdit
{
    Q_OBJECT
public:
    TxtAddrSize(QWidget *parent = 0);
    void set_value(qint64 input_value);
    qint64 get_value();
public slots:
    void txt_edit(QString str);
signals:
    void value_changed(qint64 num);
private:
    qint64 value;
    void update_display();
    void update_data(quint64 input_int);
};

#endif // TXTADDRSIZE_H
