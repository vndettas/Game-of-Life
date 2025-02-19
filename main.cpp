#include <QApplication>
#include "Simulation.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Simulation window;
    window.show();
    return app.exec();
}