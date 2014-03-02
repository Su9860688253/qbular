#ifndef LEDCUBE_H
#define LEDCUBE_H

#include <QMainWindow>

class QLabel;

class LedCube : public QMainWindow
{
public:
    LedCube(QWidget *parent = 0);

private:
    QWidget *centralWidget;
    QLabel *dummyWidget;        
};

#endif 
