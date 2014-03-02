#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);

private:
    QWidget *centralWidget;
    QLabel *dummyWidget;        
};

#endif 
