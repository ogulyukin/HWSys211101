#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QRegularExpression>
#include <QThreadPool>
#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    int getNumber();

    void process();

    void setOne(int newOne);

    void setTwo(int newTwo);

    void setCommand();

signals:

private:
    QString numberCheck(QString str);
    int one;
    int two;
    QString command;


};

#endif // MANAGER_H
