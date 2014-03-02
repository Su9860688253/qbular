#ifndef LEDCUBE_H
#define LEDCUBE_H

#include <QWidget>

class QLabel;
class QGroupBox;

class LedCube : public QWidget
{
public:
    LedCube(QWidget *parent = 0);

private:
    QLabel *simPlaceholder;
    QGroupBox *transformControls;
    QGroupBox *resControls;
    QGroupBox *spacingControls;
    QGroupBox *colorControls;
};

#endif
