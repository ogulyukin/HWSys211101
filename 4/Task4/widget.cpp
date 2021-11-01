#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseFileButton_clicked()
{
    clearData();
    path = QFileDialog::getOpenFileName(this, "Open File",
                                        "/home",
                                        tr("Text files (*.txt);;All files (*.*)"));
    if(path != "")
        ui->pathLabel->setText(path);
}


void Widget::on_startButton_clicked()
{
    int count = 0;
    if(ui->lineEdit->text() == "" || path == "")
        return;
    list = FileReader::load(path);
    QThreadPool *pool = QThreadPool::globalInstance();
    WordFinder *finder = new WordFinder(ui->lineEdit->text(), &list, &count);
    finder->setAutoDelete(true);
    pool->start(finder);
    pool->waitForDone();
    ui->wordCountLabel->setText(QString::number(count));
}

void Widget::clearData()
{
    list.clear();
    path = "";
    ui->wordCountLabel->setText("0");
    ui->pathLabel->setText("");
}

