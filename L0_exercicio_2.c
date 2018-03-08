
//Algoritmo que demonstra o uso de um vetor de ponteiros que cada ponteiro aponta para um vetor de duas posicoes

#include<stdio.h>
void algoritmo_um_ponto_dois(int paMatriz[][2],int n_linhas) {
	if (n_linhas < 2)
		return;
	int* M00 = *(paMatriz);
	int* M01 = *(paMatriz) + 1;
	int* M10 = *(paMatriz + 1);
	int* M11 = *(paMatriz + 1) + 1;

	printf("\nM00 = %d", *(M00));
	printf("\nM01 = %d", *(M01));
	printf("\nM10 = %d", *(M10));
	printf("\nM11 = %d", *(M11));

}
void imprime_matriz_elemento_estatica(int paMatriz[][2], int piLinha, int piColuna) {

	printf("%d", *(*(paMatriz + piLinha) + piColuna));
}

int main() {
	//Teste com uma matriz de duas posicoes
	int matriz[2][2] = { {1,2},{3,4} };
	algoritmo_um_ponto_dois(matriz, 2);
	
	printf("\n");
	imprime_matriz_elemento_estatica(matriz, 1, 1);
	getchar();
	return 0;
}
