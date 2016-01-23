#include "pid_controller.h"

PID_Controller::PID_Controller(double pTerm, double iTerm, double dTerm, double iMax, double iMin)
{
    this->iMax = iMax;
    this->iMin = iMin;
    this->pTerm = pTerm;
    this->iTerm = iTerm;
    this->dTerm = dTerm;

    iState = 0;
    dState = 0;
}

float PID_Controller::update(double error, double position)
{
    double pVal = 0, iVal = 0, dVal = 0;

    //P Term Calculation
    pVal = pTerm * error;

    //I Term Calculation
    iState += error;
    if (iState > iMax)
        iState = iMax;
    else if (iState < iMin)
        iState = iMin;
    iVal = iTerm * iState;

    //D Term Calculation
    dVal = dTerm * (position - dState);
    dState = position;

    return pVal + iVal + dVal;
}
