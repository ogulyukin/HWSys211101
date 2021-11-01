#ifndef WORDFINDER_H
#define WORDFINDER_H

#include <QRunnable>
#include <QStringList>
#include <QDebug>

class WordFinder : public QRunnable
{
public:
    WordFinder(QString checkWord, QStringList *list, int *count);

    // QRunnable interface
public:
    virtual void run() override;

private:
    QString checkWord;
    QStringList *list;
    int *count;
};

#endif // WORDFINDER_H
