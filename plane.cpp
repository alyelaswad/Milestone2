#include "plane.h"
#include "ui_plane.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Plane::Plane(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Plane)
{
    ui->setupUi(this);
    ui->label_4->hide();
    algorithm();
    QPixmap pix("/Users/alyalaswad/Downloads/istockphoto-1286812890-612x612 (1).jpg");
    ui->label->setPixmap(pix);
//    int w = ui->label->width();
//    int h = ui->label->height ();
//    ui->label->setPixmap (pix.scaled (w, h, Qt::KeepAspectRatio));

}
void Plane::algorithm()
{
    srand(time(0));
    QVector <int> ArrT(2);
    double Tr = 0; //X
    double WaitTotal = 0;
    int jobcount = 0;
    double t = 0;
    int i = 0;
    double Tarrival;

    while(t < Q.getTmax()|| jobcount!=i)
    {
        if((double)rand()/RAND_MAX < Q.getProbArr())
        {
            if(Q.DEQ_Length() < 10)
            {
                Tarrival = t;
                Q.Add_Rear(Tarrival);
                if(jobcount < 10){
                    ui->label_3->setText(ui->label_3->text()+" Arrival#"+QString::number(i+1) +" at: "+QString::number(Tarrival)+"\n");}
                else{
                    ui->label_2->setText(ui->label_2->text()+" Arrival#"+QString::number(i+1) +" at: "+QString::number(Tarrival)+"\n");
                }
                ArrT[i]= Tarrival;
                ArrT.resize(ArrT.size()+1);
                i++;

            }
            else
            {
                ui->label_3->setText(ui->label_3->text()+"Line is full"+"\n");
            }
        }

        if (Tr == 0 && !(Q.DEQisEmpty()))
        {
            double Tarrival = Q.View_Front()->info;

            double Tw = t - ArrT[jobcount];
            Q.Remove(Tarrival);
            WaitTotal += Tw;
            jobcount++;
            if(jobcount < 10 ){
            ui->label_3->setText(ui->label_3->text()+"Job#"+QString::number(jobcount)+" Service Started at: "+QString::number(t)+" wait = "+QString::number(Tw)+"\n");
            }else{
            ui->label_2->setText( ui->label_2->text()+"Job#"+QString::number(jobcount)+" Service Started at: "+QString::number(t)+" wait = "+QString::number(Tw)+"\n");
            }
            Tr = Q.getLanding();
        }
        if(Tr > 0)
        {
            Tr--;
        }
        t++;
    }
    double m =Q.AverageWait(WaitTotal, jobcount);
    if(jobcount < 10){
        ui->label_3->setText(ui->label_3->text()+ "Average wait time is "+QString::number(m)+"\n");}
    else {
        ui->label_2->setText(ui->label_2->text()+ "Average wait time is "+QString::number(m)+"\n");
    }
    return;


}


Plane::~Plane()
{
    delete ui;
}


void Plane::on_pushButton_clicked()
{
       ui->label_3->setText("");
    ui->label_3->hide();
       ui->label_2->hide();
    ui->label_4->show();

//    algorithm();
}





void Plane::on_pushButton_2_clicked()
{
       Plane* plane= new Plane;
       this->hide();
       plane->show();
}

