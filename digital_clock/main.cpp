#include <QApplication>
#include "digital_clock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    digital_clock clock;
    clock.show();

    return a.exec();
}
