#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    QString text_changed_wrapper(QString);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_clicked();

    void on_textEdit_textChanged();

protected:

private:
    Dialog *my_dialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
