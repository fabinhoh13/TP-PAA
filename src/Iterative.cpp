#include "Iterative.h"

Iterative::Iterative(int nitems, int weight) {
    this->weight = weight;
    //Cria um vetor, inicializando todos os elementos com 0. 
    vector<int> items(nitems, 0);
    this->items = items;
    this->value = 0;
    this->itemsInSolution = 0;

    //Aloca dinamicamente memória para um array de ponteiros para inteiros
    int** solution = new int*[nitems + 1];
    for (int i = 0; i <= nitems; i++) {
        solution[i] = new int[weight + 1];
        solution[i][0] = 0;
    }

    //inicializar o restante da matriz solution.
    for (int i = 0; i <= nitems; i++) {
        for (int j = 0; j <= weight; j++) {
            if (i == 0) {
                solution[i][j] = 0;
            } else {
                solution[i][j] = -1;
            }
        }

        solution[i][0] = 0;
    }

    this->solution = solution;
}

//destrutor da classe Iterative
Iterative::~Iterative() {

    for (int i = 0; i <= (int)this->items.size(); i++) {
        delete[] this->solution[i];
    }
    delete[] this->solution;
   
    this->items.clear();
}

//algoritmo iterativo para resolver o problema da mochila
void Iterative::solve(const Knapsack* instance) {
    
    for (int i = 1; i <= instance->getSize(); i++) {
   
        for (int j = 1; j <= instance->getCapacity(); j++) {
            Item* item = instance->getItem(i - 1);
            
            if (item->weight > j) {
                this->solution[i][j] = this->solution[i - 1][j];
            } else {
                int notInSolution = this->solution[i - 1][j];
                int inSolution = this->solution[i - 1][j - item->weight] + item->value;

                if (notInSolution > inSolution) {
                    this->solution[i][j] = notInSolution;
                } else {
                    this->solution[i][j] = inSolution;
                }
            }
        }
    }

    this->value = this->solution[instance->getSize()][instance->getCapacity()];
}