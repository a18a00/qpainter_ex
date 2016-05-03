#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::read_text(QString txt)
{
    positions.clear();
    QStringList tmp = txt.split('\n');
    for(int i=0;i<tmp.length();i++)
    {
        positions.push_back(tmp[i].toInt());
    }
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPen line_pen(Qt::gray), pen(Qt::green);
    QRect background(0,0,width(),height());
    paint.setPen(line_pen);
    QColor c = line_pen.color();
    c.setAlpha(c.alpha()/4);
    line_pen.setColor(c);
    QPoint start(0,height()/2),end(width(),height()/2);
    QBrush fill(Qt::black,Qt::SolidPattern);
    paint.fillRect(background,fill);
    paint.drawLine(start,end);
    pen.setColor(Qt::green);
    paint.setPen(pen);
    size_t len = positions.size();
    paint.drawText(5,10,QString("Ilosc punktow: %1").arg(len));
    if(len > 1)
    {
        float delta = width()/(len-1);
        float ratio;
        int _min = *std::min_element(positions.begin(), positions.end()), _max = *std::max_element(positions.begin(),positions.end());
        float maxh = std::max(abs(_min),abs(_max));
        ratio = maxh != 0 ? (height()/2)/maxh : 0;
        paint.drawText(width()/2-20,10,QString("Max = %1").arg(_max));
        paint.drawText(width()/2-20,height()-10,QString("Min = %1").arg(_min));
        start.setX(0); start.setY(height()/2-positions[0]*ratio);
        for(size_t i=1;i<len;i++)
        {
            end.setX(start.x()+delta);
            end.setY(height()/2 - positions[i]*ratio);
            paint.drawLine(start,end);
            paint.setPen(line_pen);
            paint.drawLine(end.x(),0,end.x(),height());
            paint.drawText(start.x()-10,height()-10,QString::number(i));
            paint.setPen(pen);
            start = end;
        }
    }
}
