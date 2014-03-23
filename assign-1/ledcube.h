#ifndef LEDCUBE_H
#define LEDCUBE_H

#include <QWidget>
#include "ui_ledcube.h"

class QLabel;
class QGroupBox;

/*
    A widget that consists of a simulation placeholder and four
    QBoxWidgets that contain dummy controls of the simulation.
*/
class LedCube : public QWidget
{
public:
    LedCube(QWidget *parent = 0);

private:
    Ui::LedCube ui;
};
#endif
