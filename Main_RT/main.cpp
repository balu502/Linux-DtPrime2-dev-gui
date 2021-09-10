#include "main_rt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main_RT w;

    SplashScreen *splash = new SplashScreen(&a, w.Language);
    splash->show();

    int value = 0;
    while(splash->progress->value() < 100)
    {
        Sleep(10);
        value += 2;
        splash->progress->setValue(value);
        a.processEvents();
    }
    splash->close();

    w.show();

    return a.exec();
}
