#include "BeerPong.h"

float updatePID(PID *controller, float error, float position)
{
	float pTerm, iTerm, dTerm;		
	
	//Calculate the P term
	pTerm = controller->pGain * error;
	
	//Calculate I Term
	controller->iState += error;
	if (controller->iState > controller->iMax)
		controller->iState = controller->iMax;
	else if (controller->iState < controller->iMin)
		controller->iState = controller->iMin;
	
	iTerm = controller->iGain*controller->iState;

	//Calculate the D Term
	dTerm = controller->dGain*(position - controller->dState);
	controller->dState = position;

	return pTerm + iTerm + dTerm;
}

