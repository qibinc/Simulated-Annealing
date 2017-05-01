//
// Created by 陈齐斌 on 28/04/2017.
//

#include "SA.h"

template <typename T>
SA<T>::SA(StateImp<T> *stateImp) : stateImp(stateImp)
{
	srand((unsigned int) time(0));

	temperature = InitTemperature();

	currentState = stateImp->InitState();
}

template <typename T>
void SA<T>::SimulatedAnnealing()
{
	startTime = clock();

	while (!Terminate(temperature))
	{
		int i = 0;
		while (!Balanced(i++))
		{
			newState = stateImp->Neighbor(currentState);

			double delta = stateImp->F(newState) - stateImp->F(currentState);

			if (Accepted(delta))
			{
				delete currentState;
				currentState = newState;
			}
			else
			{
				delete newState;
			}

		}

		Print();

		temperature = Drop(temperature);
	}

	delete currentState;
	std::cout << "Finished!" << std::endl;

}

template <typename T>
bool SA<T>::Accepted(double delta)
{
	return delta < 0 || pow(M_E, -delta / temperature) > (double) rand() / RAND_MAX;
}

template <typename T>
void SA<T>::Print()
{
	std::cout << "Temperature = " << temperature << std::fixed << std::setprecision(2)
	          << "\tTime = " << (double)(clock() - startTime) / CLOCKS_PER_SEC << 's' << std::endl
	          << "\tMin F = " << stateImp->F(currentState) << std::endl;
	stateImp->PrintSolution(currentState);
	std::cout << std::endl;
}

template <typename T>
double SA<T>::InitTemperature()
{
	return 300;
}

template <typename T>
bool SA<T>::Balanced(int i)
{
	return i >= 100;
}

template <typename T>
bool SA<T>::Terminate(double temperature)
{
	return temperature < 0.5;
}

template <typename T>
double SA<T>::Drop(double temperature)
{
	return 0.92 * temperature;
}

