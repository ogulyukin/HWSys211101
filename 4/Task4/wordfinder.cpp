#include "wordfinder.h"

WordFinder::WordFinder(QString checkWord, QStringList *list, int *count) : QRunnable(),
    checkWord(checkWord), list(list), count(count)
{
    qDebug() << "Creating runnable class: " << checkWord << " found words: " << list->count();
}

void WordFinder::run()
{
    int countLockal = 0;
    for(auto it = list->begin(); it != list->end(); it++)
    {
        qDebug() << *it;
        if(*it == checkWord)
            countLockal++;
    }
    *count = countLockal;

}
