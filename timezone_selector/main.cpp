#include <QApplication>
#include "timezone_selector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    timezone_selector selector;
    selector.show();

    return a.exec();
}
