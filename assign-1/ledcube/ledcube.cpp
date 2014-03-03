#include <QtGui>
#include "ledcube.h"
#include "ui_ledcube.h"

LedCube::LedCube(QWidget *parent)
    : QWidget(parent)
{
/*
    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    simPlaceholder = new QLabel();
    QPixmap *image_ptr = new QPixmap(":/images/placeholder.png");
    const QPixmap &image_ref = *image_ptr;
    simPlaceholder->setPixmap(image_ref);
    mainLayout->addWidget(simPlaceholder);
*/

    ui.setupUi(this);
}
