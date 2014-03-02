#include <QApplication>
#include "mainwindow.h"

/*
    Entry point for LedCube application
*/
int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mainWindow= new MainWindow();
    mainWindow->show();

    return app.exec();
}
