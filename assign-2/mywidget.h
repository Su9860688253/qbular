#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
class QLabel;
class QSpinBox;
class QRadioButton;
class QSlider;
class MainWidget;

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);

private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *rightLayout;

    QGroupBox *transformGroupBox;
    QGroupBox *countGroupBox;
    QGroupBox *spacingGroupBox;
    QGroupBox *colorGroupBox;

    MainWidget *mainWidget;
};
#endif
