
//Algoritmo que demonstra o uso de um vetor de ponteiros que cada ponteiro aponta para um vetor de duas posicoes
#if defined _WIN32
	#include <Windows.h>
#endif
#include<stdio.h>
#include<stdlib.h>

//Lembrete:  piLinha pertence ao intervalo [0,dimensao1)
//Lembrete:  piColuna pertence ao intervalo [0,dimensao2)



void imprime_matriz_elemento_dinamica(int** paMatriz, int piLinha, int piColuna) {

	//Poderia ter feito a verificacao de dimensoes
	//Mas no exercicio o prototipo estava fixo
	//Aritmetica de ponteiros, super ilegivel
	printf("%d", *(*(paMatriz + piLinha) + piColuna));
	// o mesmo que printf("%d", paMatriz[piLinha][piColuna]); 

}

void imprime_matriz(int** matriz, int dimensao1, int dimensao2)
{
	int i, j;
	for (i = 0; i < dimensao1; i++)
	{
		for (j = 0; j < dimensao2; j++)
		{

			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void le_matriz(int** matriz, int dimensao1, int dimensao2)
{
	int i, j;
	for (i = 0; i < dimensao1; i++)
	{
		for (j = 0; j < dimensao2; j++)
		{
			fflush(stdin);
			//Brincando com aritmetica de ponteiros #empolgante
			//Porem ilegivel
			scanf("%d", (*(matriz + i) + j));
		}
		
	}
}

int main() {
	int i,j;
	int** matriz;
	int dimensao1, dimensao2;
	
	printf("\n entre com as dimensoes da matriz\n");
	scanf("%d", &dimensao1);
	scanf("%d", &dimensao2);

	//Aloca matriz dinamica
	matriz = malloc(sizeof(int*)*dimensao1);
	for (i = 0; i < dimensao1; i++) {
		matriz[i] = malloc(sizeof(int)*dimensao2);
	}

	printf("\n De entrada nos elementos da matriz\n");
	le_matriz(matriz, dimensao1, dimensao2);
	printf("\n matriz lida\n");
	imprime_matriz(matriz, dimensao1, dimensao2);
	printf("\n");

	int posicao1, posicao2;
	printf("\n entre com dois inteiros , indices da matriz\n");
	fflush(stdin);
	scanf("%d", &posicao1);
	fflush(stdin);
	scanf("%d", &posicao2);
	printf("\n");
	if (posicao1 > 0 && posicao1 < dimensao1) {
		if (posicao2 > 0 && posicao2 < dimensao2)
			imprime_matriz_elemento_dinamica(matriz, posicao1, posicao2);
	}
	else
		printf("\nindice(s) invalido(s)\n");
	
#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32

	return 0;
}
