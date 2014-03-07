#include <QApplication>
#include "mywidget.h"

#include <iostream>

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QApplication::setStyle("motif");
    QApplication::setStyle("clearlooks");

    MyWidget *myWidget = new MyWidget();
    //myWidget->setFixedSize(myWidget->sizeHint());
    //QSize sizeMyWidget(500, 500);
    //myWidget->setFixedSize(sizeMyWidget);
    myWidget->setVisible(true);

    return app.exec();
}
