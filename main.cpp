#include "mainwindow.h"
#include "worker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Worker worker1{0., -0.02};
    Worker worker2{0.04, 0.};

    QObject::connect(&worker1, &Worker::move,
                     &w, &MainWindow::moveCircle);
    QObject::connect(&worker2, &Worker::move,
                     &w, &MainWindow::moveCircle);

    w.show();
    return a.exec();
}
