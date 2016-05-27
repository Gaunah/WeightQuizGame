#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //center window
    QRect pos = w.frameGeometry();
    pos.moveCenter(QDesktopWidget().availableGeometry().center());
    w.move(pos.topLeft());
    w.show();

    return a.exec();
}
