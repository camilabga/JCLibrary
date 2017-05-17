#include <QtGui/QApplication>
#include "librarymainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibraryMainWindow w;
    w.show();

    return a.exec();
}
