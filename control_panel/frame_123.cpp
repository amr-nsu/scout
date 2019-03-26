#include "frame_123.h"
#include <QFrame>

frame_123::frame_123(QWidget *naslednik) : QFrame(naslednik)
{

    QWidget::resize(200, 200);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    QWidget::setAutoFillBackground(true);
    QWidget::setPalette(Pal);

    coordinates.push_back(QPoint(0, 0));
    coordinates.push_back(QPoint(50, 50));
    coordinates.push_back(QPoint(-50, 50));
    coordinates.push_back(QPoint(50, -50));
    coordinates.push_back(QPoint(-50, -50));
centerPoint.setX(QWidget::width()/2);
centerPoint.setY(QWidget::height()/2);

}

void frame_123::delete_d()
{
    coordinates.clear();

}


void frame_123::setData(QVector<QPoint> coordinates)
{
    this-> coordinates = coordinates;

}

void frame_123::addPoint(QPoint p){
    this-> coordinates.push_back(p);
}




void frame_123::setScale(double size)
{
    this-> size = size;
}


void frame_123::setData(int move_x, int move_y)
{
    this-> move_x = move_x;
    this-> move_y = move_y;
}

void frame_123::setData_end(int move_x, int move_y)
{
    centerPoint.setX(centerPoint.rx()-move_x);
    centerPoint.setY(centerPoint.ry()-move_y);

}



void frame_123::paintEvent(QPaintEvent *e)
{

    qDebug() <<"frame "<< move_x << move_y;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QPen linepen(Qt::black);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(1);
    painter.setPen(linepen);

//    QPoint centerPoint(QWidget::width()/2, QWidget::height()/2);

    double n = n *= size;
    double m = m *= size;

    painter.drawLine(centerPoint.rx()-move_x,0,centerPoint.rx()-move_x,QWidget::height());
    painter.drawLine(0,centerPoint.ry()-move_y,QWidget::width(),centerPoint.ry()-move_y);

    for (n= -160; n<160; n= n+20){
        painter.drawLine(0,centerPoint.ry()-n*size-move_y,QWidget::width(),centerPoint.ry()-n*size-move_y);
        painter.drawLine(centerPoint.rx()-n*size-move_x,0,centerPoint.rx()-n*size-move_x,QWidget::height());
    }

//    painter.drawLine(centerPoint.rx()-move_x,0,centerPoint.rx()-move_x,QWidget::height());
//    painter.drawLine(0-move_x,centerPoint.ry()-move_y,QWidget::width()-move_x,centerPoint.ry()-move_y);



//    for (n= 0; n<170; n= n+20){
//    painter.drawLine(0-move_x,centerPoint.ry()-n*size-move_y,QWidget::width()-move_x,centerPoint.ry()-n*size-move_y);
//       }
//    for (n= 0; n<340; n= n+20){
//    painter.drawLine(0-move_x,centerPoint.ry()+n*size-move_y,QWidget::width()-move_x,centerPoint.ry()+n*size-move_y);
//       }

//    for (m= 0; m<340; m= m+20){
//    painter.drawLine(centerPoint.rx()-m*size-move_x,0-move_y,centerPoint.rx()-m*size-move_x,QWidget::height()-move_y);
//       }
//    for (m= 0; m<340; m= m+20){
//    painter.drawLine(centerPoint.rx()+m*size-move_x,0-move_y,centerPoint.rx()+m*size-move_x,QWidget::height()-move_y);
//       }






//    linepen = QPen(Qt::red);
//    linepen.setCapStyle(Qt::RoundCap);
//    linepen.setWidth(3);

//    painter.setPen(linepen);

//    for (int i = 0; i < coordinates.size();i = i+ 2)
//    {


//        QPoint na_karte = coordinates[i];



//        na_karte *= size;
//        na_karte += centerPoint;

//        painter.drawPoint(na_karte);
    //}

    linepen = QPen(Qt::blue);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(3);

    painter.setPen(linepen);

    for (int i = 1; i < coordinates.size();i = i+ 2)
    {


        QPoint na_karte = coordinates[i];

        na_karte *= size;
        na_karte += centerPoint - QPoint(move_x,move_y);

        painter.drawPoint(na_karte);
    }




}
