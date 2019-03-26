#ifndef FRAME_123_H
#define FRAME_123_H

#include <QFrame>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QDebug>


class frame_123 : public QFrame
{

public:
    frame_123(QWidget *naslednik);
    void setData (QVector<QPoint> coordinates);
    void addPoint(QPoint p);
    void setScale (double size);
    void delete_d ();
    void setData(int move_x, int move_y);
 void setData_end(int move_x, int move_y);


private:
    QVector<QPoint> coordinates;
    double size = 1;
int move_x = 0 , move_y = 0;
QPoint centerPoint;



private slots:
    void paintEvent(QPaintEvent *);


};

#endif // FRAME_123_H
