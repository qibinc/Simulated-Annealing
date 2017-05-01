//
// Created by 陈齐斌 on 28/04/2017.
//

#ifndef SA_SA_H
#define SA_SA_H

#include "StateImp.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

template <typename T>
class SA
{
private:
	clock_t startTime;

	double temperature;

	T *currentState, *newState;

	StateImp<T> *stateImp;

	bool Accepted(double delta);

	void Print();

protected:
	virtual double InitTemperature();

	virtual bool Balanced(int i);

	virtual bool Terminate(double temperature);

	virtual double Drop(double temperature);

public:
	SA(StateImp<T> *stateImp);

	void SimulatedAnnealing();
};

#endif //SA_SA_H
