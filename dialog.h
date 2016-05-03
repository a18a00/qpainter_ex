#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void read_text(QString);

protected:
    void paintEvent(QPaintEvent*);

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    std::vector<int> positions;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
