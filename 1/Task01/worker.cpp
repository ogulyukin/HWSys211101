#include "worker.h"

Worker::Worker(bool mode, QObject *parent) : QObject(parent), count(0), mode(mode)
{
    qInfo() << "Constructed on " << QThread::currentThread();
    timer.setInterval(2000);
    connect(&timer, &QTimer::timeout, this, &Worker::timeout);
}

Worker::~Worker()
{
    if(timer.isActive())
        timer.stop();
    qInfo() << "Deconstructed on " << QThread::currentThread();
}

int Worker::start()
{
    qInfo() << this << " Started on " << QThread::currentThread();
    timer.start();
    loop.exec();
    qInfo() << this << " Loop finished on " << QThread::currentThread();
    delete this;
    return count == 10 ? 0 : count;
}

void Worker::stop()
{
    qInfo() << this << " Stopping on " << QThread::currentThread();
    timer.stop();
    loop.quit();
    qInfo() << this << " Stopped on " << QThread::currentThread();
}

void Worker::timeout()
{
    qInfo() << this << " Timeout on " << QThread::currentThread();
    count++;
    qDebug() << "Count: " << count;
    if (count == 10 && mode)
        stop();
}
