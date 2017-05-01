//
// Created by 陈齐斌 on 28/04/2017.
//

#ifndef SA_TSPSTATEIMP_H
#define SA_TSPSTATEIMP_H

#include "StateImp.h"
#include "StateImp.cpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
class TSPStateImp : public StateImp<std::vector<int>>
{
private:
	int n;
	double *x, *y;
	double *adjacencyMatrix;

public:
	virtual ~TSPStateImp();

	TSPStateImp();

	void InitData() override;

	std::vector<int> *InitState() override;

	std::vector<int> *Neighbor(std::vector<int> *currentState) override;

	double F(std::vector<int> *state) override;

	void PrintSolution(std::vector<int> *state) override;
};

#endif //SA_TSPSTATEIMP_H
