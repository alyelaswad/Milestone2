#include "airplanewaitingqueue.h"
#include "deque.h"
#include "deque.cpp"
#include <QString>



double AirplaneWaitingQueue ::RandNum(int i, int j)
{
    unsigned int seed = time(NULL);
    const unsigned int a = 25173;
    const unsigned int b = 13849;
    const unsigned int m = 65536;

    int x = (a * seed + b) % m;
    seed = x;

    double r = double(seed) / double(65536);
    return (i + r * (j - i));
}
void AirplaneWaitingQueue ::Arrival()
{

    //    double R = RandNum(0, 1);
    //    if (R < probArr)
    //    {
    //        Tarrival = t;
    //        // DEQ FULL

    //        this->Add_Rear(Tarrival);
    //    }
}

void AirplaneWaitingQueue ::ExitLine(double t, double &waitTotal, int &jobcount)
{
    if (this->DEQisEmpty())
    {
        // EMPTY
        return;
    }
    else
    {
        double Tarrival = this->View_Front()->info;
        this->Remove_Front();
        double Tw = t - Tarrival;
        waitTotal += Tw;
        jobcount++;
        //        AirplaneWaitingQueue::Plane::OUT(jobcount,t,Tw);

    }
    //    if (AirplaneWaitingQueue::DEQisEmpty())
    //    {
    //        // OUT LINE IS EMPTY
    //    }
    //    else
    //    {
    //        Tarrival=this->View_Front()->info;
    //        AirplaneWaitingQueue::Remove_Front();
    //        WaitTime = t;
    //    }
}

AirplaneWaitingQueue::AirplaneWaitingQueue() : Tmax(25),avTime(4)
{
    probArr = 1 / avTime;
    tLanding = 3;


}

void AirplaneWaitingQueue ::Service(double t, double &Tr, double &waitTotal, int &jobcount)
{
    if (Tr == 0 && !(this->DEQisEmpty()))
    {
        ExitLine(t, waitTotal, jobcount);
        Tr = tLanding;
    }
    //    if (RemTime == 0 && AirplaneWaitingQueue::DEQisEmpty())
    //    {
    //        ExitLine();
    //        RemTime = tLanding;
    //    }
}

double AirplaneWaitingQueue ::AverageWait(double WaitTotal, int jobcount)
{
    if (jobcount == 0)
    {
        return 0;
    }
    else
    {
        return(WaitTotal/jobcount);
    }
}



AirplaneWaitingQueue ::~AirplaneWaitingQueue()
{
}



// Getter for probArr
double AirplaneWaitingQueue::getProbArr()  {
    return probArr;
}

double AirplaneWaitingQueue::getavTime()  {
    return avTime;
}

double AirplaneWaitingQueue::getTmax()  {
    return Tmax;
}


// Setter for probArr
void AirplaneWaitingQueue::setProbArr(double probArro) {
    probArr = probArro;
}





void AirplaneWaitingQueue::setLanding(double landing){
    tLanding = landing;
}

double AirplaneWaitingQueue::getLanding()
{
    return tLanding;
}
