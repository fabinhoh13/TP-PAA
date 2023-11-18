#include "Backtrack.h"
#include "Backtrack2.h"
#include "BranchAndBound.h"
#include "Iterative.h"

#include <stdbool.h>
#include <time.h>

int main (int argc, char *argv[]) {
    
    int op = atoi(argv[1]); // Opção de algoritmo selecionada

    int tamanho = atoi(argv[2]); // tamanho do instância que será ordenada
    double tempo[20];                            // variável que armazena cada iteração das instâncias
    FILE *instancia;                             // arquivo de instância
    clock_t inicio, fim;                         // varíaveis auxiliares para cronometrar tempo
    char caminho_arq[200];                       // variável para armazenar caminho até arquivo de entrada
    string algoritmo; // variável para armazenar nome do algoritmo;
    int nIntances = 20; // número de instâncias
    if (op == 4)
    {
        cout << "Segundo Teste" << endl << endl;
        int len = 400;
        for (int i = 1; i <= 20; i++)
        {
            
            sprintf(caminho_arq, "../input/a2/n%d/weight-W%d-%d.in", tamanho, tamanho, i);
            int pesoM;
            instancia = fopen(caminho_arq, "r");
            int pesoI, valorI;
            fscanf(instancia, "%d", &pesoM);
            Knapsack *k = new Knapsack(pesoM, len);
            for (int j = 0; j < len; j++)
            {
                fscanf(instancia, "%d %d", &pesoI, &valorI);
                k->insert(new Item(j, pesoI, valorI));
            }
            Iterative *it = new Iterative(len, pesoM);
            inicio = clock();
            it->solve(k);
            fim = clock();

            cout << "Instancia " << i << ": " << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;

            fclose(instancia);
        }
    }
    else
    {
        if (op == 1)
        {
            algoritmo = "Iterative";
        }

        else if (op == 2)
        {
            algoritmo = "BranchAndBound";
        }

        else if (op == 3)
        {
            if (tamanho >= 40)
                nIntances = 5;
            else if (tamanho >= 50)
                nIntances = 1;
            algoritmo = "Backtrack";
        }

        cout << "Algoritmo: " << algoritmo << endl << endl;
        double media = 0.0;
        for (int i = 1; i <= nIntances; i++)
        {
            
            sprintf(caminho_arq, "../input/a1/n%d/instance-n%d-%d.in", tamanho, tamanho, i);
            int pesoM;
            instancia = fopen(caminho_arq, "r");
            int pesoI, valorI;
            fscanf(instancia, "%d", &pesoM);
            Knapsack *k = new Knapsack(pesoM, tamanho);
            for (int j = 0; j < tamanho; j++)
            {
                fscanf(instancia, "%d %d", &pesoI, &valorI);
                k->insert(new Item(j, pesoI, valorI));
            }

            if (op == 1)
            {
                Iterative *it = new Iterative(tamanho, 100);
                inicio = clock();
                it->solve(k);
                fim = clock();
            }

            else if (op == 2)
            {
                BranchAndBound *bb = new BranchAndBound(tamanho, 100);
                inicio = clock();
                bb->solve(k);
                fim = clock();
            }

            else if (op == 3)
            {
                Backtrack2 *bt = new Backtrack2();
                inicio = clock();
                bt->solve(k);
                fim = clock();
            }
            cout << "Instancia " << i << ": " << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
            media += (double)(fim - inicio) / CLOCKS_PER_SEC;

            fclose(instancia);
        }
        media /= 20.0;
        cout << endl << "Media: " << media << endl;
    }
    return 0;
}