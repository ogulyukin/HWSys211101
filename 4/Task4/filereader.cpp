#include "filereader.h"

FileReader::FileReader(QObject *parent) : QObject(parent)
{

}

QStringList FileReader::load(QString path)
{
    QFile file(path);
    QStringList list;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return list;
    }
    QTextStream stream(&file);
    QString line = stream.readAll();
    line.replace("\n", " ");
    list = line.split(" ");
    return list;
}
