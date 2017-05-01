//
// Created by 陈齐斌 on 28/04/2017.
//

#include "TSPStateImp.h"

void TSPStateImp::InitData()
{
	std::cin >> n;
	x = new double[n];
	y = new double[n];

	for (int i = 0; i < n; ++i)
		std::cin >> x[i];

	for (int j = 0; j < n; ++j)
		std::cin >> y[j];

	adjacencyMatrix = new double[n * n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			adjacencyMatrix[i * n + j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

std::vector<int> *TSPStateImp::InitState()
{
	std::vector<int> *initState = new std::vector<int>;

	for (int i = 0; i < n; ++i)
		initState->push_back(i);

	srand((unsigned int) time(0));

	return initState;
}

std::vector<int> *TSPStateImp::Neighbor(std::vector<int> *currentState)
{
	std::vector<int> *newState = new std::vector<int>;

	int u = rand() % n, v = rand() % n;

	if (u > v)
	{
		std::swap(u, v);
	}

	for (auto iter = currentState->begin(); iter != currentState->begin() + u; ++iter)
	{
		newState->push_back(*iter);
	}

	for (auto iter = currentState->begin() + v; iter != currentState->begin() + u - 1; --iter)
	{
		newState->push_back(*iter);
	}

	for (auto iter = currentState->begin() + v + 1; iter != currentState->end(); ++iter)
	{
		newState->push_back(*iter);
	}

	return newState;
}

double TSPStateImp::F(std::vector<int> *state)
{
	double f = 0;

	for (auto iter = state->begin(); iter != state->end() - 1; ++iter)
		f += adjacencyMatrix[*iter * n + *(iter + 1)];
	f += adjacencyMatrix[state->front() * n + state->back()];

	return f;
}

void TSPStateImp::PrintSolution(std::vector<int> *state)
{
	std::cout << '\t';
	for (auto iter = state->begin(); iter != state->end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

}

TSPStateImp::~TSPStateImp()
{
	if (x != nullptr)
		delete x;
	if (y != nullptr)
		delete y;
	if (adjacencyMatrix != nullptr)
		delete adjacencyMatrix;
}

TSPStateImp::TSPStateImp()
{
	x = y = adjacencyMatrix = nullptr;
}
