#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H


class PID_Controller
{
public:
    PID_Controller(double pTerm = 0, double iTerm = 0, double dTerm = 0, double iMax = 50, double iMin = -50);
    float update(double error, double position);


private:
    double pTerm;
    double iTerm;
    double dTerm;
    double iState;
    double dState;

    double iMax;
    double iMin;

};

#endif // PID_CONTROLLER_H
