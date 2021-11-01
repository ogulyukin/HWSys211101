#include "worker.h"

Worker::Worker(int one, int two, QString command) : QRunnable(),
    one(one), two(two), command(command)
{

}

void Worker::run()
{
    qDebug() << "This is thread: " << QThread::currentThread();
    if(command == "+")
    {
        qInfo() << one << " + " << two << " = " << (one + two);
    }else if(command == "-")
    {
        qInfo() << one << " - " << two << " = " << (one - two);
    }else if(command == "*")
    {
        qInfo() << one << " * " << two << " = " << (one * two);
    }else if(command == "/")
    {
        if(two == 0)
        {
            qWarning() << "Can't divide 0!";
            return;
        }
        qInfo() << one << " / " << two << " = " << ((double)one / two);
    }else
    {
        qInfo() << "Command is invalid!!!";
    }
}
