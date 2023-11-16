#include "Backtrack.h"
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

    if (op == 4)
    {
        int len = 400;
        for (int i = 1; i <= 20; i++)
        {
            
            sprintf(caminho_arq, "../input/a2/n%d/weight-W%d-%d.in", tamanho, tamanho, i);
            printf ("%s\n", caminho_arq);
            int pesoM;
            instancia = fopen(caminho_arq, "r");
            if (instancia == NULL)
            {
                cout << "Erro ao abrir arquivo" << endl;
                exit(1);
            }
            int pesoI, valorI;
            fscanf(instancia, "%d", &pesoM);
            Knapsack *k = new Knapsack(pesoM, len);

            for (int j = 0; j < len; j++)
            {
                fscanf(instancia, "%d %d", &pesoI, &valorI);
                k->insert(new Item(j, pesoI, valorI));
            }

            Iterative *it = new Iterative(len, 100);
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
            algoritmo = "BranchAndBound";
        }

        cout << "Algoritmo: " << algoritmo << endl << endl;
        double media = 0.0;
        for (int i = 1; i <= 20; i++)
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
                inicio = clock();
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