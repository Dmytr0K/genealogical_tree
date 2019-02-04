#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mw = new MainWindow;
    mw->setGeometry(40,200,1200,600);
    mw->show();

    return a.exec();
}
