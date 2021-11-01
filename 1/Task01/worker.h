#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QEventLoop>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(bool mode, QObject *parent = nullptr);
    ~Worker();

signals:

public slots:
    int start();
    void stop();
    void timeout();

private:
    QTimer timer;
    QEventLoop loop;
    int count;
    bool mode;
};

#endif // WORKER_H
