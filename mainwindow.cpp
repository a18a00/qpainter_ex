#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_dialog = new Dialog(this);
    connect(this,SIGNAL(text_changed_wrapper(QString)),my_dialog,SLOT(read_text(QString)));
    my_dialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(!my_dialog->isVisible())
        my_dialog->show();
}

QString text_changed_wrapper(QString param)
{
    return param;
}

void MainWindow::on_textEdit_textChanged()
{
    my_dialog->update();
    emit text_changed_wrapper(ui->textEdit->toPlainText());
}
