#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{

}

int Manager::getNumber()
{
    QTextStream cin(stdin);
    QString number;
    cin >> number;
    number = numberCheck(number);
    if(number == "")
    {
        qFatal("It is not a number!!!");
    }
    qInfo() << "Accepted: " << number;
    return number.toInt();
}

void Manager::process()
{
    QThreadPool *pool = QThreadPool::globalInstance();
    Worker *worker = new Worker(one, two, command);
    worker->setAutoDelete(true);
    pool->start(worker);
    pool->waitForDone();
}

QString Manager::numberCheck(QString str)
{
    return str.remove(QRegularExpression("\\D"));
}

void Manager::setCommand()
{
    QTextStream cin(stdin);
    cin >> command;
}

void Manager::setTwo(int newTwo)
{
    two = newTwo;
}

void Manager::setOne(int newOne)
{
    one = newOne;
}
