#include "mybackground.h"

MyBackground::MyBackground(QWidget *parent, QString background)
    : QWidget{parent}
{
    this->setFixedSize(400, 700);

    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QPixmap(background).scaled(this->size())));
    setPalette(pal);

    blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(5);
    this->setGraphicsEffect(blureffect);
}

void MyBackground::SetBlurEffect(int k)
{
    blureffect->setBlurRadius(k);
    this->setGraphicsEffect(blureffect);
}
