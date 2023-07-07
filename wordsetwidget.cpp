#include "wordsetwidget.h"
#include <QLabel>

WordSetWidget::WordSetWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(400, 700);
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(255,255,255, 200)));
    setPalette(pal);
    //设置标题
    QLabel* label = new QLabel(this);
    //设置标题内容
    label->setText("我的词库");
    //设置标题内容居中
    label->setAlignment(Qt::AlignCenter);
    //设置大小
    label->resize(320, 40);
    //移动到目标位置
    label->move(40, 0);

    //设置退出按钮
    exit_btn = new QPushButton(this);
    //设置大小
    exit_btn->resize(40, 40);
    exit_btn->setStyleSheet("border-image:url(:/img/down.png);");

    //设置全部已经学习的词汇
    learned_btn = new BasicButton(this, 255, 0, 0);
    //设置大小
    learned_btn->resize(380, 40);
    //移动到目标位置
    learned_btn->move(10, 100);

    learned_btn->setOpacity(50);

    //设置生词本栏目
    newWord_btn = new BasicButton(this);
    //设置大小
    newWord_btn->resize(380, 40);
    //移动到目标位置
    newWord_btn->move(10, 250);

    //设置句库栏目
    newWord_btn = new BasicButton(this);
    //设置大小
    newWord_btn->resize(380, 40);
    //移动到目标位置
    newWord_btn->move(10, 400);

    //设置笔记栏目
    newWord_btn = new BasicButton(this);
    //设置大小
    newWord_btn->resize(380, 40);
    //移动到目标位置
    newWord_btn->move(10, 550);
}
