#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QThreadPool>
#include "filereader.h"
#include "wordfinder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_chooseFileButton_clicked();

    void on_startButton_clicked();

private:
    Ui::Widget *ui;
    QStringList list;
    QString path;
    void clearData();
};
#endif // WIDGET_H
