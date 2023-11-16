#ifndef ITERATIVE_H
#define ITERATIVE_H

#include "Knapsack.h"

class Iterative {
    private:
    int weight;           // Peso atual da mochila
    int value;            // Valor monetário da mochila
    int itemsInSolution;  // Número de itens na solução
    vector<int> items;    // Vetor binário representando cada item; 1 significa, que faz parte da solução.
                          //  A posição representa o índice do item.


    int** solution;  // Matriz de solução; Linha = item, Coluna = peso.

   public:
    Iterative(int nitems, int weight);
    ~Iterative();

    /**
    * Para uma instância dada, resolve o problema da mochila de forma iterativa usando uma tabela de solução.
    * @param instance  é a instância dos dados.
    */
    void solve(const Knapsack* instance);

};

#endif