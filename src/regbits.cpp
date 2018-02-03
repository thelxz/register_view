#include "regbits.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
#include <QLineEdit>
#include "lineedits.h"
#include <QCheckBox>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

Regbits::Regbits(QWidget *parent)
    : QWidget(parent)
{
    main_int = 0;
    intbits = new Intbits();
    lineedits = new LineEdits();
    bit_operate = new BitOperate();
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(intbits,0,0,1,4);
    mainLayout->addWidget(lineedits,0,5,2,3);
    mainLayout->addWidget(bit_operate,1,0,1,1);
#ifdef Q_OS_WIN
    ckbox_always_on_top = new QCheckBox("OnTop");
    mainLayout->addWidget(ckbox_always_on_top,1,1,1,1);
    connect(this->ckbox_always_on_top,SIGNAL(stateChanged(int)),this,SLOT(set_alway_on_top(int)));
#endif
    setLayout(mainLayout);
    connect(this->intbits,SIGNAL(value_changed(quint64)),this,SLOT(set_main_int(quint64)));
    connect(this->lineedits,SIGNAL(value_changed(quint64)),this,SLOT(set_main_int(quint64)));
    connect(this->bit_operate,SIGNAL(value_changed(quint64)),this,SLOT(set_main_int(quint64)));
    this->set_main_int(0);
    //this->setFixedSize(this->width(),this->height());
    //this->setFixedSize(1200,150);

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
    if(this->bit_operate->get_value()!=input_int)
        this->bit_operate->set_value(input_int);
}

#ifdef Q_OS_WIN
void Regbits::set_alway_on_top(int cke_state){
    if (cke_state==Qt::Unchecked){
        SetWindowPos((HWND)winId(),HWND_NOTOPMOST,pos().x(),pos().y(),width(),height(),SWP_SHOWWINDOW);
    }
    else{
        SetWindowPos((HWND)winId(),HWND_TOPMOST,pos().x(),pos().y(),width(),height(),SWP_SHOWWINDOW);
    }
}
#endif
