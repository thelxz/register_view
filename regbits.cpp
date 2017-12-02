#include "regbits.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
#include <QLineEdit>
#include "lineedits.h"

Regbits::Regbits(QWidget *parent)
    : QWidget(parent)
{
    main_int = 0;
    intbits = new Intbits();
    lineedits = new LineEdits();
    //this->setFixedSize(800,200);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(intbits,0,0,1,4);
    mainLayout->addWidget(lineedits,0,5,2,3);
    setLayout(mainLayout);
    connect(this->intbits,SIGNAL(value_changed(quint64)),this,SLOT(set_main_int(quint64)));
    connect(this->lineedits,SIGNAL(value_changed(quint64)),this,SLOT(set_main_int(quint64)));
}

Regbits::~Regbits()
{

}

void Regbits::set_main_int(quint64 input_int)
{
    this->main_int = input_int;
    if(this->intbits->get_value()!=input_int)
        this->intbits->set_value(input_int);
    if(this->lineedits->get_value()!=input_int)
        this->lineedits->set_value(input_int);
}
