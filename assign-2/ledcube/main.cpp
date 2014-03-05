#include <QApplication>
#include "mywidget.h"

#include <iostream>

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget *myWidget = new MyWidget();
    myWidget->setFixedSize(myWidget->sizeHint());
    myWidget->setVisible(true);

    return app.exec();
}
