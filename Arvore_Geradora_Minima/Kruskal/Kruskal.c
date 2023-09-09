#include <stdio.h>
#include <stdlib.h>

#define NUMERO_VERTICES 6 // Ordem do grafo

int i, j, a, b, u, v, numero_arestas = 1;
int custo_minimo, custo_minimo_arvore = 0, vertice_pai[6];

int Fecho_Transitivo(int k){
	while(vertice_pai[k]){
       k = vertice_pai[k];
	}
	return k;
}
int Verifica_Ciclo(int l,int p){
	if(l != p)
	{
		vertice_pai[p] = l;
		return 1;
	}
	return 0;
}


void main(){

	system("cls");
	printf("\tAlgoritmo de Kruskal\n\n");

	// Preenchimento da matriz de adjacencia do grafo

	int grafo[NUMERO_VERTICES][NUMERO_VERTICES] = {
	    { 0, 10,  0,  0,  0, 8 },
        { 10, 0,  1,  2, -4, 0 },
        { 0,  1,  0, -2,  0, 0 },
        { 0,  2, -2,  0, -1, 0 },
        { 0, -4,  0, -1,  0, 1 },
        { 8,  0,  0,  0,  1, 0 }
    };

	printf("\tArvore Geradora Minima\n\n");

	// Numero de arestas da arvore deve ser igual ao numero de vertices subtraido de 1

	while(numero_arestas < NUMERO_VERTICES){

        // Percorre a matriz em busca de arestas entre os
        // vertices e verifica qual e a aresta de custo minimo

		for(i = 0, custo_minimo = 999999; i < NUMERO_VERTICES; i++){
			for(j = 0; j < NUMERO_VERTICES; j++){
				if( (grafo[i][j] != 0) && (grafo[i][j] < custo_minimo) ){
					custo_minimo = grafo[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}

		// Percorre o fecho transitivo do vertice

		u = Fecho_Transitivo(u); // i = 1
		v = Fecho_Transitivo(v); // j = 4

		// Verifica se existe o ciclo. Se nao existir, imprime a aresta da arvore

		if(Verifica_Ciclo(u,v)){
			printf("\tAresta %d: (%d,%d) = %d\n", numero_arestas++, a + 1, b + 1, custo_minimo);
			custo_minimo_arvore += custo_minimo;
		}

		// Inclui aresta na lista de arestas incluidas

		grafo[a][b] = grafo[b][a] = 999999;

	}

	printf("\n\tCusto minimo = %d\n", custo_minimo_arvore);

    printf("\n");
	system("pause");

}
