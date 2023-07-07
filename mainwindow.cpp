#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "wordsetwidget.h"

#include <QGraphicsOpacityEffect>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口大小
    this->setFixedSize(400, 700);

    //加载背景图片
    background_widget = new MyBackground(this);
    background_widget->SetBlurEffect(0);
    //构建词库界面
    wordSet_widget = new WordSetWidget(this);
    //将词库界面移动到底部
    wordSet_widget->move(0, 700);
    wordSet_widget->show();

    //添加词库界面
    adding_widget = new AddingWidget(this);
    adding_widget->move(-400, 0);
    adding_widget->show();
    //添加cardset对象
    cardSetP = new CardSet(this);
    adding_widget->setCardSet(cardSetP);

    //复习词汇界面
    review_widget = new ReviewWidget(this, cardSetP, 3);
    review_widget->move(400, 0);
    review_widget->show();

    //设置开始界面
    main_widget = new MainWidget(this);
    SetMainPage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete data_widget;
}

//设置stackWidget的MainPage
void MainWindow::SetMainPage()
{
    int animation_time = 200;
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
    connect(main_widget->wordSet_btn, &myLabelButton::clicked, this, [=](){
        wordSet_widget->raise();
        main_widget->hide();
        animation->start();
        background_widget->SetBlurEffect(blurValue);
    });
    //点击词库退出词库界面
    connect(wordSet_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation2->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });

    //connect 添加词汇
    connect(main_widget->addNew_btn, &myLabelButton::clicked, this, [=](){
        adding_widget->raise();
        main_widget->hide();
        animation3->start();
        background_widget->SetBlurEffect(blurValue);
    });
    connect(adding_widget->exit_btn, &QPushButton::clicked, this, [=](){
        adding_widget->clearContent();
        animation4->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });

    //connect 复习词汇
    connect(main_widget->review_btn, &myLabelButton::clicked, this, [=](){
        review_widget->raise();
        review_widget->refresh();
        animation5->start();
        main_widget->hide();
        background_widget->SetBlurEffect(blurValue);
    });
    connect(review_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation6->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });
}
