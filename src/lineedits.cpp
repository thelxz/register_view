#include "lineedits.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QRegExp>
#include <QValidator>
#include "txtaddrsize.h"

LineEdits::LineEdits(QWidget *parent) : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout;
    this->setFixedSize(300,120);
    mainLayout->setSpacing(0);
    numHex = new QLineEdit();
    numOct = new QLineEdit();
    numDec = new QLineEdit();
    numBin = new QLineEdit();
    txt_addr_size = new TxtAddrSize();
    numHex->setMaxLength(16);
    numOct->setMaxLength(22);
    numDec->setMaxLength(20);
    numBin->setMaxLength(64);
    labelHex = new QLabel("Hex:");
    labelOct = new QLabel("Oct:");
    labelDec = new QLabel("Dec:");
    labelBin = new QLabel("Bin:");
    labelAddrsize = new QLabel("Size:");

    // regexp
    QRegExp rx_hex("[0-9a-fA-F]*");
    QValidator *hex_validator = new QRegExpValidator(rx_hex, this);
    numHex->setValidator(hex_validator);
    QRegExp rx_dec("[0-9]*");
    QValidator *dec_validator = new QRegExpValidator(rx_dec, this);
    numDec->setValidator(dec_validator);
    QRegExp rx_oct("[0-7]*");
    QValidator *oct_validator = new QRegExpValidator(rx_oct, this);
    numOct->setValidator(oct_validator);
    QRegExp rx_bin("[0-1]*");
    QValidator *bin_validator = new QRegExpValidator(rx_bin, this);

    numBin->setValidator(bin_validator);
    mainLayout->addWidget(this->labelHex,0,0,1,1);
    mainLayout->addWidget(this->labelDec,1,0,1,1);
    mainLayout->addWidget(this->labelOct,2,0,1,1);
    mainLayout->addWidget(this->labelBin,3,0,1,1);
    mainLayout->addWidget(this->labelAddrsize,4,0,1,1);
    mainLayout->addWidget(this->numHex,0,1,1,5);
    mainLayout->addWidget(this->numDec,1,1,1,5);
    mainLayout->addWidget(this->numOct,2,1,1,5);
    mainLayout->addWidget(this->numBin,3,1,1,5);
    mainLayout->addWidget(this->txt_addr_size,4,1,1,5);
    this->setLayout(mainLayout);
    connect(numHex,SIGNAL(textEdited(QString)),this,SLOT(hex_text_changed(QString)));
    connect(numDec,SIGNAL(textEdited(QString)),this,SLOT(dec_text_changed(QString)));
    connect(numOct,SIGNAL(textEdited(QString)),this,SLOT(oct_text_changed(QString)));
    connect(numBin,SIGNAL(textEdited(QString)),this,SLOT(bin_text_changed(QString)));
    connect(txt_addr_size,SIGNAL(value_changed(quint64)),this,SLOT(txt_addr_size_changed(quint64)));

    connect(numHex,SIGNAL(editingFinished()),this,SLOT(check_empty()));
    connect(numDec,SIGNAL(editingFinished()),this,SLOT(check_empty()));
    connect(numOct,SIGNAL(editingFinished()),this,SLOT(check_empty()));
    connect(numBin,SIGNAL(editingFinished()),this,SLOT(check_empty()));
    connect(txt_addr_size,SIGNAL(editingFinished()),this,SLOT(check_empty()));
    this->check_empty();
    this->set_value(0);
}
void LineEdits::update_display()
{
    QString str_hex = QString::number(this->int_num,16).toUpper();
    QString str_dec = QString::number(this->int_num,10);
    QString str_oct = QString::number(this->int_num,8);
    QString str_bin = QString::number(this->int_num,2);
    bool ok;
    if(this->numHex->text().toULongLong(&ok,16) != this->int_num)
        this->numHex->setText(str_hex);
    if(this->numDec->text().toULongLong(&ok,10) != this->int_num)
        this->numDec->setText(str_dec);
    if(this->numOct->text().toULongLong(&ok,8) != this->int_num)
        this->numOct->setText(str_oct);
    if(this->numBin->text().toULongLong(&ok,2) != this->int_num)
        this->numBin->setText(str_bin);
    if(this->txt_addr_size->get_value() != this->int_num)
        this->txt_addr_size->set_value(this->int_num);
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
void LineEdits::txt_addr_size_changed(quint64 value){
     update_data(value);
}

void LineEdits::check_empty(){
    if (this->numHex->text() == "")
        numHex->setText("0");
    if (this->numDec->text() == "")
        numDec->setText("0");
    if (this->numOct->text() == "")
        numOct->setText("0");
    if (this->numBin->text() == "")
        numBin->setText("0");
    if (this->txt_addr_size->text() == "")
        txt_addr_size->set_value(0);
}
