#include "Backtrack2.h"

Backtrack2::Backtrack2() {}

void Backtrack2::solve(Knapsack *instance)
{
    int index = 0;
    BackTrack(instance, index);
}

void Backtrack2 :: BackTrack(Knapsack *instance, int index)
{
    if (index == instance->getSize())
    {
        if (actualValue > bestValue)
        {
            bestValue = actualValue;
        }
        return;
    }
    if (instance->getCapacity() - instance->getItem(index)->weight >= 0)
    {
        actualValue += instance->getItem(index)->value;
        instance->setChosen(index, 1);
        BackTrack(instance, index + 1);
        instance->setChosen(index, 0);
        actualValue -= instance->getItem(index)->value;
    }
    BackTrack(instance, index + 1);
}