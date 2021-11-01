#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent), runMode(false)
{

}

Manager::~Manager()
{
    quit();
}

void Manager::finished(int result)
{
    qInfo() << "Process finished with result code: " << result;
}

void Manager::process()
{
    future = QtConcurrent::run(Manager::createWorker, this);
    watcher.setFuture(future);
    if(runMode)
    {
        watcher.waitForFinished();
        qInfo() << "Process finished with result code: " << future.result();
    }
}

void Manager::quit()
{
    qInfo() << "Stop manager";
    emit stop();
    if(!runMode)
    {
        qInfo() << "Process finished with result code: " << future.result();
    }
}

int Manager::createWorker(Manager *manager)
{
    qInfo() << "Create manager";
    Worker* worker = new Worker(manager->getRunMode());
    connect(manager, &Manager::stop, worker, &Worker::stop, Qt::QueuedConnection);
    return worker->start();
}

bool Manager::getRunMode() const
{
    return runMode;
}

void Manager::setRunMode(bool newRunMode)
{
    runMode = newRunMode;
    if (runMode){
        qDebug() << "Run mode is set to wait for complete";
    }else{
        qDebug() << "Run mode is set to wait for QIUT command";
    }
}
