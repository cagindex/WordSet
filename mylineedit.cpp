#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent)
    : QWidget{parent}
{
    this->resize(340, 40);
    lineEdit = new QLineEdit(this);
    edit = new QCheckBox(this);
    //设置lineEdit
    lineEdit->resize(270, 40);
    lineEdit->move(0, 0);

    //设置edit
    edit->resize(60, 20);
    edit->setText("编辑");
    edit->move(280, 10);

    //初始化lineEdit
    lineEdit->setEnabled(false);

    connect(edit, &QCheckBox::stateChanged, lineEdit, [=](){
        if(edit->isChecked()) lineEdit->setEnabled(true);
        else lineEdit->setEnabled(false);
    });
}


void myLineEdit::setText(const QString& s)
{
    lineEdit->setText(s);
}
QString myLineEdit::text()
{
    return lineEdit->text();
}
