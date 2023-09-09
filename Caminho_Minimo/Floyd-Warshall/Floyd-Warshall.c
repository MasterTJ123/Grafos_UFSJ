#include <stdio.h>
#include <stdlib.h>

#define NUMERO_VERTICES 6 // Quantidade de vertices do grafo

#define INF 9999 // Representacao do infinito

void imprimirSolucao(int distancia[][NUMERO_VERTICES]);

// Funcao para calcular o caminho minimo atraves do algoritmo de Floyd-Warshall

void floydWarshall (int Grafo[][NUMERO_VERTICES])
{

    // Distancia minima atual entre cada um dos pares de vertices

    int distancia[NUMERO_VERTICES][NUMERO_VERTICES];
    int i = 0, j = 0, k = 0;

    // Preenche a matriz de distancias com as distancias iniciais, incluindo as com valor "INFINITO"

    for (i = 0; i < NUMERO_VERTICES; i++){
        for (j = 0; j < NUMERO_VERTICES; j++){
            distancia[i][j] = Grafo[i][j];
        }
    }

    // Caso seja encontrada uma distancia menor entre 2 vertices, atualiza essa distancia na matriz de distancias

    for (k = 0; k < NUMERO_VERTICES; k++){
        for (i = 0; i < NUMERO_VERTICES; i++){
            for (j = 0; j < NUMERO_VERTICES; j++){
                if ( (distancia[i][k] + distancia[k][j] < distancia[i][j]) && (distancia[i][k] != INF) && (distancia[k][j] != INF) ){
                    distancia[i][j] = distancia[i][k] + distancia[k][j];
                }
            }
        }
    }

    // Chama a funcao que imprime o resultado

    imprimirSolucao(distancia);
}

// A funcao imprime o resultado do algoritmo

void imprimirSolucao(int distancia[][NUMERO_VERTICES])
{

    printf ("MATRIZ DE DISTANCIAS ENTRE OS PARES DE VERTICES\n\n");

    for (int i = 0; i < NUMERO_VERTICES; i++){
        for (int j = 0; j < NUMERO_VERTICES; j++){
            if (distancia[i][j] == INF){
                printf("%7s", "INF");
            } else {
                printf ("%7d", distancia[i][j]);
            }
        }
        printf("\n\n");
    }

}

int main()
{
    // Representação do grafo em matriz

    int Grafo[NUMERO_VERTICES][NUMERO_VERTICES] = {
        {   0,  10, INF, INF, INF,   8 },
        { INF,   0, INF,   2, INF, INF },
        { INF,   1,   0, INF, INF, INF },
        { INF, INF,  -2,   0, INF, INF },
        { INF,  -4, INF,  -1,   0, INF },
        { INF, INF, INF, INF,   1,   0 }
    };

    // Floyd-Warshall e impressão do resultado

    floydWarshall(Grafo);
    system("pause");
    return 0;

}
