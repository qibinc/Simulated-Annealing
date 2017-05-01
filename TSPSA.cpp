//
// Created by 陈齐斌 on 28/04/2017.
//

#include "TSPSA.h"

TSPSA::TSPSA(StateImp<std::vector<int>> *stateImp) : SA<std::vector<int>>(stateImp)
{
	size = stateImp->InitState()->size();
}

bool TSPSA::Balanced(int i)
{
	return i > 100 * size;
}
