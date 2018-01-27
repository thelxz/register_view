#include "txtaddrsize.h"

TxtAddrSize::TxtAddrSize(QWidget *parent):QLineEdit(parent)
{
    this->value = 0;
    update_display();
    connect(this,SIGNAL(textEdited(QString)),this,SLOT(txt_edit(QString)));
}

void TxtAddrSize::txt_edit(QString str){

}


void TxtAddrSize::set_value(qint64 input_value){
    this->value = input_value;
    update_display();
}

qint64 TxtAddrSize::get_value(){
    return this->value;
}

void TxtAddrSize::update_display(){

}

void TxtAddrSize::update_data(quint64 input_int)
{
    this->value = input_int;
    update_display();
    emit value_changed(input_int);
}
