#include "TSPSA.h"
#include "TSPStateImp.h"
#include <vector>

int main()
{
	StateImp<std::vector<int>> *tspImp = new TSPStateImp();

	tspImp->InitData();

	SA<std::vector<int>> *tspSA = new TSPSA(tspImp);

	tspSA->SimulatedAnnealing();

	delete tspImp;

	delete tspSA;

	return 0;
}
