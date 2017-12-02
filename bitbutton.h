#ifndef BITBUTTON_H
#define BITBUTTON_H
#include <QWidget>
#include <QPushButton>

class BitButton : public QPushButton
{
    Q_OBJECT
public:
    explicit  BitButton(QWidget *parent = 0);
signals:
    void bittoggled();
public slots:
    void bitbtnclick();
};

#endif // BITBUTTON_H
