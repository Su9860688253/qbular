#include <QApplication>
#include "mywidget.h"

#include <iostream>

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget *myWidget = new MyWidget();
    //myWidget->setFixedSize(myWidget->sizeHint());
    QSize sizeMyWidget(500, 500);
    myWidget->setFixedSize(sizeMyWidget);
    myWidget->setVisible(true);

    return app.exec();
}
