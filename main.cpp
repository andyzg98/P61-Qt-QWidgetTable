#include "principal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //estilo fusion de pantalla
    Principal w;
    w.show();
    return a.exec();
}
