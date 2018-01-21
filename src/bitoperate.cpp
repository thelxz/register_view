#include "bitoperate.h"
#include <QGridLayout>
#include <QPushButton>

BitOperate::BitOperate(QWidget *parent) : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    btn_clear = new QPushButton("clear", this);
    btn_reverse = new QPushButton("reverse", this);
    mainLayout->addWidget(btn_clear,0,0,1,1);
    mainLayout->addWidget(btn_reverse,0,1,1,1);
    this->setLayout(mainLayout);
    connect(btn_clear,SIGNAL(clicked(bool)),this,SLOT(clear_num()));
    connect(btn_reverse,SIGNAL(clicked(bool)),this,SLOT(reverse_num()));
}

void BitOperate::set_value(quint64 input_num){
    this->int_num = input_num;
}
quint64 BitOperate::get_value(){
    return this->int_num;
}
void BitOperate::clear_num(){
    this->int_num = 0;
    emit value_changed(this->int_num);
}
void BitOperate::reverse_num(){
    this->int_num = ~int_num;
    emit value_changed(this->int_num);
}
