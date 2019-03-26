#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    frame = new frame_123(this);
    ui->verticalLayout->addWidget(frame);






    connect(&serial,&QSerialPort::readyRead,this, &MainWindow::lisent_serial);



    serial.setPortName("/dev/ttyUSB0");
    serial.setBaudRate(QSerialPort::Baud57600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    if (serial.open(QIODevice::ReadWrite)){
        ui->label->setText("open");

    }
    else{
        ui->label->setText("no open");
    }





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    serial.write("q");
}



void MainWindow::lisent_serial(){


    data += serial.readLine();
    if (data.endsWith("\r\n")) {
        ui->label->setText(data);




        QString str = data;
        data.clear();


        QStringList list1 = str.split(' ');
        if (list1.size() >1){
            QString ygol = list1[0];
            //QString distance = list1[1];
            QString Dist_laser = list1[1];
            QString robot_course = list1[2];
            QString x_robot = list1[3];
            QString y_robot = list1[4];
            QString SUMMA = list1[5];


            float SUMMA1 = SUMMA.toFloat();
            float ygolInt   = ygol.toFloat();
            //float distanceInt   = distance.toFloat();
            float Dist_laserInt = Dist_laser.toFloat();
            float robot_course1 = robot_course.toFloat();
            float x_robot1 = x_robot.toFloat();
            float y_robot1 = y_robot.toFloat();
            float S1 = (ygolInt+Dist_laserInt+robot_course1+x_robot1+y_robot1);

            if (SUMMA1 == S1){
                ygolInt = (ygolInt+robot_course1) *  M_PI / 180;

                //float x = distanceInt * cos(ygolInt);
                //float y = distanceInt * sin(ygolInt);
                float y1 = (Dist_laserInt) * sin(ygolInt);
                float x1 = (Dist_laserInt)* cos(ygolInt);

                x1 = x1+x_robot1;
                y1 = y1+y_robot1;

                //frame->addPoint(QPoint (x,-y));
                frame->addPoint(QPoint(x1, -y1));
                frame->update();

                qDebug() << str;
                qDebug() << ygolInt << " " <<Dist_laserInt;

            }


        }
        else{
            qDebug() << "test";
            qDebug() << str;
        }


    }

}

void MainWindow::on_pushButton_2_clicked()
{
    frame->delete_d();
    frame->update();
}



void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    frame->setScale(arg1);
    frame->update();



    //ui->label->setText();
}

void MainWindow::on_label_2_objectNameChanged(const QString &objectName)
{

}


void MainWindow::keyPressEvent(QKeyEvent *event){
    int code=event->key();
 qDebug() << code;
    switch ( code )
    {
      case 87: { // w
          qDebug() << "w";
          serial.write("w");
          ui->label_3->setText("Forward");

          break;
        }
      case 83: { // s
          qDebug() << "s";
          serial.write("s");
           ui->label_3->setText("Backwards");
          break;
        }
      case 65: { // a
          qDebug() << "a";
          serial.write("a");
           ui->label_3->setText("Turn left");
          break;
        }
      case 68: { //d
         qDebug() << "d";
         serial.write("d");
          ui->label_3->setText("Turn right");
          break;
        }
      case 81: { // q
          qDebug() << "q";
          serial.write("q");
           ui->label_3->setText("Scanning");
          break;
        }

//      case 70: { // f
//          qDebug() << "f";
//          serial.write("f");
//          break;
//        }
//      case 82: { // r
//          qDebug() << "r";
//          serial.write("r");
//          break;
//        }

      case 69: { // e
          qDebug() << "e";
          serial.write("e");
           ui->label_3->setText("Stop");
          //calcData.clear();
          //scan();
          break;
        }

    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
 qDebug() << "P " << QString::number(event->pos().x())<< " " << QString::number(event->pos().y());

 move_x = press_x - event->pos().x();
 move_y = press_y - event->pos().y();
 frame -> setData_end(move_x,move_y);
}

  void MainWindow::mousePressEvent(QMouseEvent *event){

      qDebug() << "Press " << QString::number(event->pos().x())<< " " << QString::number(event->pos().y());
      press_x = event->pos().x();
      press_y = event->pos().y();
      qDebug() << press_x << press_y;

  }
  void MainWindow::mouseMoveEvent(QMouseEvent *event)
    {

    qDebug() << QString::number(event->pos().x())<< " " << QString::number(event->pos().y());
    move_x = press_x - event->pos().x();
    move_y = press_y - event->pos().y();
    qDebug() << move_x << move_y;
    frame ->setData(move_x,move_y);
    frame->update();
  }


