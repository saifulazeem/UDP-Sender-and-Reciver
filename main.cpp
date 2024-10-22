#include "Udp_reciver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Udp_reciver w;
    w.show();
    return a.exec();
}
