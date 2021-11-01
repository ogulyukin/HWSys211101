#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QTextStream>
#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

signals:
    void start();
    void stop();

public slots:
    void finished(int result);

public:
    void process();
    void quit();
    void mode();

    void setRunMode(bool newRunMode);

    bool getRunMode() const;

private:
    static int createWorker(Manager* manager);
    QFuture<int> future;
    QFutureWatcher<int> watcher;
    bool runMode;

};

#endif // MANAGER_H
