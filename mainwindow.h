#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cardset.h"
#include "wordsetwidget.h"
#include "addingwidget.h"
#include "mainwidget.h"
#include "reviewwidget.h"
#include "mybackground.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString GetDate();

    void SetMainPage();
    void ShowWordSetWidget();

    ~MainWindow();
private:
    Ui::MainWindow *ui;
    //设置虚化值
    int blurValue = 10;

    QWidget* data_widget;
    //词库动画对象
    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
    //添加词汇动画对象
    QPropertyAnimation* animation3;
    QPropertyAnimation* animation4;
    //复习词汇动画对象
    QPropertyAnimation* animation5;
    QPropertyAnimation* animation6;
    //背景图片对象
    MyBackground* background_widget;
    //主界面对象
    MainWidget* main_widget;
    //词库对象
    WordSetWidget* wordSet_widget;
    //添加词汇对象
    AddingWidget* adding_widget;
    //复习词汇对象
    ReviewWidget* review_widget;
    //卡库对象
    CardSet* cardSetP;
};
#endif // MAINWINDOW_H
