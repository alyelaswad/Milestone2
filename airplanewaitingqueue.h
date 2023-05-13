#ifndef AIRPLANEWAITINGQUEUE_H
#define AIRPLANEWAITINGQUEUE_H
#include "deque.h"
#include <QLabel>
//#include "plane.h"

class AirplaneWaitingQueue : public Deque
{
private:
    const double Tmax;
    double tLanding;
    const double avTime;
    double probArr;

    // one sec
public:

    AirplaneWaitingQueue();
    ~AirplaneWaitingQueue();


    double getProbArr();

    double getTmax();

    double getavTime();

    void setProbArr(double probArro);

    double RandNum(int i, int j);

    void setLanding(double landing);

    double getLanding();

    void Arrival();

    void Service(double t, double &Tr, double &waitTotal, int &jobcount);

    void ExitLine(double t, double &waitTotal, int &jobcount);

    double AverageWait(double WaitTotal, int jobcount);


};

#endif // AIRPLANEWAITINGQUEUE_H
