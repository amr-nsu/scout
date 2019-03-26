#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "frame_123.h"
#include "math.h"
#include <QKeyEvent>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void lisent_serial();
    void on_pushButton_2_clicked();
     void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void on_doubleSpinBox_valueChanged(double arg1);
    void mouseMoveEvent(QMouseEvent *event);
    void on_label_2_objectNameChanged(const QString &objectName);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    frame_123* frame;
    QSerialPort serial;
    QByteArray  data;
    int press_x = 0, press_y = 0, move_x= 0, move_y = 0;
};

#endif // MAINWINDOW_H
