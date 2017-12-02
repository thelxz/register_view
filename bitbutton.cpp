#include "bitbutton.h"
#include <QPushButton>
#include <QWidget>

BitButton::BitButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(bitbtnclick()));
}

void BitButton::bitbtnclick()
{
    if (this->text()=="1")
        this->setText("0");
    else
        this->setText("1");
    emit bittoggled();
}
