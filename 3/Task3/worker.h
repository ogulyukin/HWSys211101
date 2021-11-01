#ifndef WORKER_H
#define WORKER_H

#include <QRunnable>
#include <QDebug>
#include <QThread>

class Worker : public QRunnable
{
public:
    Worker(int one, int two, QString command);

private:
    int one;
    int two;
    QString command;

    // QRunnable interface
public:
    virtual void run() override;
};

#endif // WORKER_H
