#include <QCoreApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager manager;
        QTextStream cin(stdin);
        qInfo() << "Run mode: wait for command";
        qInfo() << "Type START to begin";
        qInfo() << "Type QUIT to quit";
        qInfo() << "Type MODE to change run mode. Current mode is waiting for QUIT command mode";
        QThread::currentThread()->setObjectName("Main Thread");
        qInfo() << "This is main thread data: " << QThread::currentThread();
        forever
        {
            QString command;
            cin >> command;

            if (command.toUpper() == "START")
            {
                manager.process();
            }else if(command.toUpper() == "QUIT")
            {
                manager.quit();
            }else if(command.toUpper() == "MODE")
            {
                manager.setRunMode(manager.getRunMode() ? false : true);
            }
        }

    return a.exec();
}
