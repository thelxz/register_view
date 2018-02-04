#include "txtaddrsize.h"
#include <QRegExp>
#include <QDebug>

TxtAddrSize::TxtAddrSize(QWidget *parent):QLineEdit(parent)
{
    this->value = 0;
    update_display();
    connect(this,SIGNAL(textEdited(QString)),this,SLOT(txt_edit(QString)));
    connect(this,SIGNAL(textChanged(QString)),this,SLOT(txt_check_vaild(QString)));
}

// if input not valid string, red it and the value not changed
void TxtAddrSize::txt_edit(QString str){
    if (is_valid_str(str)){
       update_data(get_num_of_str(str));
    }
}

void TxtAddrSize::txt_check_vaild(QString str){
    if (!is_valid_str(str))
        this->setStyleSheet("QLineEdit { background-color: #FF8888 }");
    else
        this->setStyleSheet("");
}

void TxtAddrSize::set_value(qint64 input_value){
    this->value = input_value;
    update_display();
}

quint64 TxtAddrSize::get_value(){
    return value;
}

/**********************
    B       1B
    1k   1024B = 2^10B
    1M   1024B = 2^20B
    1G   1024B = 2^30B
    1T   1024B = 2^40B
    1P   1024B = 2^50B
    1E   1024B = 2^60B
***********************/
QString TxtAddrSize::get_str_of_num(quint64 input_num){
    QString tmp_str;
    for (int i=6;i>=0;i--){
        count[i]= (input_num >> (i*10)) % 1024;
        if (count[i] != 0){
            tmp_str.append(QString::number(count[i])+unit[i]);
        }
    }
    if (tmp_str == ""){
        tmp_str = "0B";
    }
    return tmp_str;
}

quint64 TxtAddrSize::get_num_of_str(QString input_str){
    quint64 tmp_num;
    //QString pattern("^(\\d+E)*(\\d+P)*(\\d+T)*(\\d+G)*(\\d+M)*(\\d+K)*(\\d+B)*$");
    QString pattern("^(?:(\\d+)E)?(?:(\\d+)P)?(?:(\\d+)T)?(?:(\\d+)G)?(?:(\\d+)M)?(?:(\\d+)K)?(?:(\\d+)B)?$");
    QRegExp rx(pattern);
    rx.exactMatch(input_str.toUpper());
    qDebug() << input_str;
    qDebug() << rx.cap(1).toULongLong();
    qDebug() << rx.cap(2).toULongLong();
    qDebug() << rx.cap(3).toULongLong();
    qDebug() << rx.cap(4).toULongLong();
    qDebug() << rx.cap(5).toULongLong();
    qDebug() << rx.cap(6).toULongLong();
    qDebug() << rx.cap(7).toULongLong();
    tmp_num =   ( rx.cap(1).toULongLong() << 60 ) +
                ( rx.cap(2).toULongLong() << 50 ) +
                ( rx.cap(3).toULongLong() << 40 ) +
                ( rx.cap(4).toULongLong() << 30 ) +
                ( rx.cap(5).toULongLong() << 20 ) +
                ( rx.cap(6).toULongLong() << 10 ) +
                rx.cap(7).toULongLong();
    return tmp_num;
}

bool TxtAddrSize::is_valid_str(QString input_str){
    QString pattern("^(?:(\\d+)E)?(?:(\\d+)P)?(?:(\\d+)T)?(?:(\\d+)G)?(?:(\\d+)M)?(?:(\\d+)K)?(?:(\\d+)B)?$");
    QRegExp rx(pattern);
    if (rx.exactMatch(input_str.toUpper())){
        if ((rx.cap(1).toInt()>15) ||		//for EB, 64bit_num < 16 EB
            (rx.cap(2).toInt()>1023) ||
            (rx.cap(3).toInt()>1023) ||
            (rx.cap(4).toInt()>1023) ||
            (rx.cap(5).toInt()>1023) ||
            (rx.cap(6).toInt()>1023) ||
            (rx.cap(7).toInt()>1023) ||
            (rx.cap(1).length()>4)   ||
            (rx.cap(2).length()>4)   ||
            (rx.cap(3).length()>4)   ||
            (rx.cap(4).length()>4)   ||
            (rx.cap(5).length()>4)   ||
            (rx.cap(6).length()>4)   ||
            (rx.cap(7).length()>4)
            )
            return false;
        else
            return true;
    }
    else
        return false;
}

void TxtAddrSize::update_display(){
    QString tmp_str = get_str_of_num(this->value);
    this->setText(tmp_str);
}

void TxtAddrSize::update_data(quint64 input_int)
{
    this->value = input_int;
    //update_display();
    emit value_changed(input_int);
}
