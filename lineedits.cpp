#include "lineedits.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>

LineEdits::LineEdits(QWidget *parent) : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    this->setFixedSize(300,120);
    mainLayout->setSpacing(0);
    numHex = new QLineEdit();
    numOct = new QLineEdit();
    numDec = new QLineEdit();
    numBin = new QLineEdit();
    labelHex = new QLabel("Hex:");
    labelOct = new QLabel("Oct:");
    labelDec = new QLabel("Dec:");
    labelBin = new QLabel("Bin:");
    mainLayout->addWidget(this->labelHex,0,0,1,1);
    mainLayout->addWidget(this->labelDec,1,0,1,1);
    mainLayout->addWidget(this->labelOct,2,0,1,1);
    mainLayout->addWidget(this->labelBin,3,0,1,1);
    mainLayout->addWidget(this->numHex,0,1,1,5);
    mainLayout->addWidget(this->numDec,1,1,1,5);
    mainLayout->addWidget(this->numOct,2,1,1,5);
    mainLayout->addWidget(this->numBin,3,1,1,5);
    this->setLayout(mainLayout);
    connect(numHex,SIGNAL(textEdited(QString)),this,SLOT(hex_text_changed(QString)));
    connect(numDec,SIGNAL(textEdited(QString)),this,SLOT(dec_text_changed(QString)));
    connect(numOct,SIGNAL(textEdited(QString)),this,SLOT(oct_text_changed(QString)));
    connect(numBin,SIGNAL(textEdited(QString)),this,SLOT(bin_text_changed(QString)));
}
void LineEdits::update_display()
{
    QString str_hex = QString::number(this->int_num,16);
    QString str_dec = QString::number(this->int_num,10);
    QString str_oct = QString::number(this->int_num,8);
    QString str_bin = QString::number(this->int_num,2);
    if(this->numHex->text()!=str_hex)
        this->numHex->setText(str_hex);
    if(this->numDec->text()!=str_hex)
        this->numDec->setText(str_dec);
    if(this->numOct->text()!=str_oct)
        this->numOct->setText(str_oct);
    if(this->numBin->text()!=str_bin)
        this->numBin->setText(str_bin);
}
void LineEdits::update_data(quint64 input_int)
{
    this->int_num = input_int;
    update_display();
    emit value_changed(input_int);
}

void LineEdits::set_value(quint64 input_num)
{
    this->int_num = input_num;
    this->update_display();
}

quint64 LineEdits::get_value()
{
    return this->int_num;
}

void LineEdits::hex_text_changed(QString str)
{
    quint64 str_num;
    bool ok;
    str_num = str.toULongLong(&ok,16);
    update_data(str_num);
}
void LineEdits::dec_text_changed(QString str)
{
     quint64 str_num;
     bool ok;
     str_num = str.toULongLong(&ok,10);
     update_data(str_num);
}
void LineEdits::oct_text_changed(QString str)
{
     quint64 str_num;
     bool ok;
     str_num = str.toULongLong(&ok,8);
     update_data(str_num);
}
void LineEdits::bin_text_changed(QString str)
{
     quint64 str_num;
     bool ok;
     str_num = str.toULongLong(&ok,2);
     update_data(str_num);
}
