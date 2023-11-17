#include "Knapsack.h"

class Backtrack2 {
private:
    int actualValue = 0;
    int bestValue = 0;


public:
    Backtrack2();
    void solve (Knapsack *instance);
    void BackTrack (Knapsack *instance, int index);
};