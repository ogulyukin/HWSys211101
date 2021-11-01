#include <QCoreApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    Manager manager;
    forever{
        qInfo() << "The main thread data: " << QThread::currentThread();
        qDebug() << "****************************************************";
        qDebug() << "Enter First number: ";
        manager.setOne(manager.getNumber());
        qDebug() << "Enter Second number: ";
        manager.setTwo(manager.getNumber());
        qDebug() << "Enter operation: ";
        manager.setCommand();
        manager.process();
    }

    return a.exec();
}
