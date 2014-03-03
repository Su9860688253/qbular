#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class LedCube;

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = 0);

private:
    LedCube *ledCube;
};
#endif 
