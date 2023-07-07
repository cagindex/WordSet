#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    //General paramete
    //词库高度
    int wordSet_height = 60;
    //动画执行时间 (单位 毫秒）
    int animation_time = 400;
    //添加词汇和复习词汇的左上角坐标
    QPoint btn_pos(10, 550);
    //添加词汇和复习词汇的高度
    int btn_height = 60;
    //添加词汇和复习词汇的水平间距
    int btns_dis = 50;

    //添加词汇和复习词汇的宽度
    int btn_width = (this->width() - (2*btn_pos.rx()) - btns_dis)/2;

    //创建词库按钮
    wordSet_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称为词库
    wordSet_btn->setText("词库");
    //调整大小
    wordSet_btn->myResize(this->width() + 100, wordSet_height);
    //移动至目标位置
    wordSet_btn->myMove(-50, this->height() - wordSet_btn->height());

    //创建添加新词界面
    addNew_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称
    addNew_btn->setText("添加词汇");
    //调整大小
    addNew_btn->myResize(QSize(btn_width, btn_height));
    //移动至目标位置
    addNew_btn->myMove(btn_pos);


    //复习词汇目标位置
    QPoint review_pos(btn_pos.rx() + btn_width + btns_dis, btn_pos.ry());
    //创建复习词汇界面
    review_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称
    review_btn->setText("复习词汇");
    //调整大小
    review_btn->myResize(btn_width, btn_height);
    //移动至目标位置
    review_btn->move(review_pos);


    /**
     * Animation part
     */
    //设置词库进入动画
    animation = new QPropertyAnimation(wordSet_widget, "pos");
    animation->setStartValue(QPoint(0, this->height()));
    animation->setEndValue(QPoint(0, 0));
    animation->setDuration(animation_time);
    //构造词库退出动画
    animation2 = new QPropertyAnimation(wordSet_widget, "pos");
    animation2->setStartValue(QPoint(0, 0));
    animation2->setEndValue(QPoint(0, this->height()));
    animation2->setDuration(animation_time);


    //设置添加词汇进入动画
    animation3 = new QPropertyAnimation(adding_widget, "pos");
    animation3->setStartValue(QPoint(-400, 0));
    animation3->setEndValue(QPoint(0, 0));
    animation3->setDuration(animation_time);
    //设置添加词汇退出动画
    animation4 = new QPropertyAnimation(adding_widget, "pos");
    animation4->setStartValue(QPoint(0, 0));
    animation4->setEndValue(QPoint(-400, 0));
    animation4->setDuration(animation_time);

    //设置复习词汇进入动画
    animation5 = new QPropertyAnimation(review_widget, "pos");
    animation5->setStartValue(QPoint(400, 0));
    animation5->setEndValue(QPoint(0, 0));
    animation5->setDuration(animation_time);
    //设置复习词汇退出动画
    animation6 = new QPropertyAnimation(review_widget, "pos");
    animation6->setStartValue(QPoint(0, 0));
    animation6->setEndValue(QPoint(400, 0));
    animation6->setDuration(animation_time);

    //点击词库进入词库界面
    connect(wordSet_btn, &myLabelButton::clicked, this, [=](){
        wordSet_widget->raise();
        animation->start();
    });
    //点击词库退出词库界面
    connect(wordSet_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation2->start();
    });

    //connect 添加词汇
    connect(addNew_btn, &myLabelButton::clicked, this, [=](){
        adding_widget->raise();
        animation3->start();
    });
    connect(adding_widget->exit_btn, &QPushButton::clicked, this, [=](){
        adding_widget->clearContent();
        animation4->start();
    });

    //connect 复习词汇
    connect(review_btn, &myLabelButton::clicked, this, [=](){
        review_widget->raise();
        review_widget->refresh();
        animation5->start();
    });
    connect(review_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation6->start();
    });



    /**
     * 这里打算建一个date对象
     */
    calendar = new Calendar(this, 255, 255, 255, 155);
    calendar->move(123, 200);

}
