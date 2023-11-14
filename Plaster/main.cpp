#include "mainwindow.h"
#include "plaster.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Plaster plasterWindow;

    // Set properties for the main window (optional)
    plasterWindow.setWindowTitle("Huiiii");
    plasterWindow.setGeometry(100, 100, 800, 600);

    // Show the Plaster window
    plasterWindow.show();
    return a.exec();
}
