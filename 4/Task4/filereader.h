#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = nullptr);
    static QStringList load(QString path);

signals:

};

#endif // FILEREADER_H
