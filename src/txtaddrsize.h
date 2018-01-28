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
    void txt_check_vaild(QString str);
signals:
    //only emit this signal when value changed by GUI
    void value_changed(quint64 num);
private:
    qint64 	value;
    uint    count[7] = {0};
    QString unit[7] = {"B", "K", "M", "G", "T", "P", "E"};// "Z", "Y", "B"};
    void update_display();
    void update_data(quint64 input_int);
    QString get_str_of_num(quint64 input_num);
    bool is_valid_str(QString input_str);
    quint64 get_num_of_str(QString input_str);
};

#endif // TXTADDRSIZE_H
