//
// Created by 陈齐斌 on 28/04/2017.
//

#ifndef SA_STATEIMP_H
#define SA_STATEIMP_H

template <typename T>
class StateImp
{
public:
	virtual ~StateImp() {};

	virtual T *InitState() = 0;

	virtual T *Neighbor(T* currentState) = 0;

	virtual double F(T* state) = 0;

	virtual void PrintSolution(T *state) {};

	virtual void InitData() = 0;
};


#endif //SA_STATEIMP_H
