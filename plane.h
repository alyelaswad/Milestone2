#ifndef PLANE_H
#define PLANE_H

#include <QMainWindow>
#include <QString>
#include <QVector>

#include "airplanewaitingqueue.h"
#include "deque.h"
#include"node.h"
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class Plane; }
QT_END_NAMESPACE

class Plane : public QMainWindow
{
    Q_OBJECT

public:
    Plane(QWidget *parent = nullptr);

    ~Plane();

private slots:


    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Plane *ui;
    void algorithm();
    AirplaneWaitingQueue Q;

};
#endif // PLANE_H
