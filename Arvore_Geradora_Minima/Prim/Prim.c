#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMERO_VERTICES 6 // Ordem do grafo
#define INFINITO 999999 // Representacao do infinito

// Acha o vertice de menor custo que ainda nao foi incluido na Arvore Geradora Minima e retorna o seu indice

int Valor_Minimo(int custo[], bool vertices_incluidos[]){

	int custo_minimo = INFINITO;
	int indice_custo_minimo;

	for (int k = 0; k < NUMERO_VERTICES; k++)
		if (vertices_incluidos[k] == false && custo[k] < custo_minimo){
			custo_minimo = custo[k];
			indice_custo_minimo = k;
		}

	return indice_custo_minimo;

}

// Imprime a Arvore Geradora Minima no console

int Imprimir_Arvore_Geradora_Minima(int vertice_pai[], int grafo[NUMERO_VERTICES][NUMERO_VERTICES]){

    printf("\tARVORE GERADORA MINIMA\n\n");

	printf("\tAresta \tPeso\n\n");
	for (int i = 1; i < NUMERO_VERTICES; i++){
        printf("\t%d - %d \t%d\n", vertice_pai[i] + 1, i + 1, grafo[i][vertice_pai[i]]);
	}

	printf("\n");
	system("pause");

}

// Algoritmo de Prim para calcular a Arvore Geradora Minima

void Prim(int grafo[NUMERO_VERTICES][NUMERO_VERTICES]){

	int vertice_pai[NUMERO_VERTICES];
	int custo[NUMERO_VERTICES];
	bool vertices_incluidos[NUMERO_VERTICES];

	// Inicializacao de todos os custos com infinito

	for (int i = 0; i < NUMERO_VERTICES; i++){
        custo[i] = INFINITO;
        vertices_incluidos[i] = false;
	}

	// Custo do primeiro vertice e sempre zero
	// e ele nao possui um vertice pai

	custo[0] = 0;
	vertice_pai[0] = -1;

	for (int i = 0; i < NUMERO_VERTICES - 1; i++) {

		int u = Valor_Minimo(custo, vertices_incluidos);

		// Inclui o vertice na Arvore Geradora Minima

		vertices_incluidos[u] = true;

		for (int j = 0; j < NUMERO_VERTICES; j++){

			// Verifica se existe alguma aresta que liga os vertices u e j,
			// se o vertice j ja foi incluido na arvore e se o peso da aresta uj
			// e menor do que o custo atual do vertice j

			if (grafo[u][j] && vertices_incluidos[j] == false && grafo[u][j] < custo[j]){
                vertice_pai[j] = u;
                custo[j] = grafo[u][j];
			}

		}


	}

	Imprimir_Arvore_Geradora_Minima(vertice_pai, grafo);

}

int main(){

    // Preenchimento da matriz de adjacencia do grafo

	int grafo[NUMERO_VERTICES][NUMERO_VERTICES] = {
	    { 0, 10,  0,  0,  0, 8 },
        { 10, 0,  1,  2, -4, 0 },
        { 0,  1,  0, -2,  0, 0 },
        { 0,  2, -2,  0, -1, 0 },
        { 0, -4,  0, -1,  0, 1 },
        { 8,  0,  0,  0,  1, 0 }
    };

	Prim(grafo);

	return 0;
}
