#ifndef LEDCUBE_H
#define LEDCUBE_H

#include <QMainWindow>

class QLabel;

class LedCube : public QMainWindow
{
public:
    LedCube();

private:
    QLabel *dummyWidget;        
};

#endif 
