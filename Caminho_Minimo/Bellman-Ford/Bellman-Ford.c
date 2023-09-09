#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMERO_VERTICES 6 // Ordem do grafo
#define INF 999999 // Representacao do infinito

// Funcao para imprimir a distancia minima entre o vertice inicial e os demais vertices

void imprimeCusto(int Custo[], int Rota[], int Numero_de_Vertices) {

    printf("Vetor Custo do grafo: {");

    int i;
    for (i = 0; i < Numero_de_Vertices - 1; i++) {
        printf("%d, ", Custo[i]);
    }
    printf("%d}\n\n", Custo[i]);

    printf("Vetor Rotas do grafo: {");

    int j;
    for (j = 0; j < Numero_de_Vertices - 1; j++){
        printf("%d, ", Rota[j]);
    }
    printf("%d}", Rota[j]);

}

// Estrutura que representa um arco/aresta

typedef struct arco {
    int origem;
    int destino;
    int peso;
} arco;

// Funcao para calcular a distancia minima entre o vertice inicial e os demais vertices

void bellmanFord(int Grafo[][NUMERO_VERTICES], int Rota[], int ordem, int vertice_origem, int Custo[]) {

    // Aloca memoria dinamicamente para o vetor "A"

    arco* A = NULL;
    A = (arco*) malloc(ordem * ordem * sizeof(arco));

    // Preenche o vetor de arcos com todos os arcos do grafo

    int n_Arcos = 0;
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if (Grafo[i][j]) {
                A[n_Arcos].origem = i;
                A[n_Arcos].destino = j;
                A[n_Arcos].peso = Grafo[i][j];
                n_Arcos++;
            }
        }
    }

    // Inicializa o vetor "Custo" com infinito

    for (int i = 0; i < ordem; i++) {
        Custo[i] = INF;
    }

    // O custo ate o vertice de origem e zero

    Custo[vertice_origem] = 0;

    for (int i = 0; i < ordem; i++) {
        Rota[i] = 0;
    }

    bool trocou;

    // Preenche o vetor "Custo" com o custo para visitar cada vertice

    for (int i = 0; i < ordem; i++) {
        trocou = false;
        for (int j = 0; j < n_Arcos; j++) {
            if (Custo[A[j].destino] > Custo[A[j].origem] + A[j].peso) {
                Custo[A[j].destino] = Custo[A[j].origem] + A[j].peso;
                Rota[A[j].destino] = A[j].origem + 1;
                trocou = true;
            }
        }
        if (!trocou){
            break;
        }
    }

    free(A);
    A = NULL;

}

int main()
{
    int Custo[NUMERO_VERTICES];
    int Rota[NUMERO_VERTICES];

    // Aqui inserimos a matriz de adjacencia do grafo, lembrando que ele nao pode
    // possuir ciclos negativos e que a contagem de vertices comeca a partir do 1

    int Grafo[NUMERO_VERTICES][NUMERO_VERTICES] = {
        { 0, 10,  0,  0, 0, 8 },
        { 0,  0,  0,  2, 0, 0 },
        { 0,  1,  0,  0, 0, 0 },
        { 0,  0, -2,  0, 0, 0 },
        { 0, -4,  0, -1, 0, 0 },
        { 0,  0,  0,  0, 1, 0 }
    };

    bellmanFord(Grafo, Rota, NUMERO_VERTICES, 0, Custo);

    imprimeCusto(Custo, Rota, NUMERO_VERTICES);

    printf("\n\n");
    system("pause");

    return 0;
}
