#include<stdio.h>
#ifdef _WIN32
#include<Windows.h>
#endif // _WIN32
#include<stdlib.h>

//1. Crie uma função em C que receba como parâmetro o tamanho de um vetor e
//proceda com a alocação dinâmica
//deste vetor retornando o endereço de memória em que o vetor está alocado.
//Utilize a função free para
//desalocar o vetor ao final do programa.
int* questao1_alocar(int size_v){
	if (size_v < 1)
		return NULL;

	return (int*) malloc((size_v) * sizeof(int));
}

int* questao1_desalocar(int* vetor,int tamanho) {
	int i;
	free(vetor);
	return NULL;
}

//2. Crie uma função em C que receba um vetor alocado dinamicamente e seu 
//tamanho atual assim como a
//quantidade de novos blocos serão alocados para este vetor.
//Proceda com a realocação do vetor usando realloc
//e retorne o endereço de memória do vetor.Utilize a função free para desalocar o vetor 
//ao final do programa.

int* questao2_realoca_vetor(int* vetor, int size_v, int new_size_v) {

	if (size_v < 0)
		size_v = 0;
	if (new_size_v < 0)
		new_size_v = 0;
	if (size_v == 0 && new_size_v == 0)
		return NULL;

	return realloc(vetor, size_v + new_size_v);
}

/*
3. Crie uma função que receba um vetor dinâmico como parâmetro e imprima todos os elementos do mesmo.
*/
void questao3(int* vetor, int size_v) {

	if (size_v < 1||vetor==NULL) 
		return;

	int i;
	for (i = 0; i < size_v; i++)
		printf(" %d ", vetor[i]);
}


/*
4. Crie uma função em C que receba como parâmetros o número de Linhas e
Colunas de uma matriz e realize a
sua alocação dinâmica na memória.Após a alocação a função deverá ter 
como retorno o endereço da matriz
alocada, conforme o texto disponível no capítulo 2 no moodle.|
*/
int** questao4(int linhas, int colunas) {

	int** matriz = NULL;
	int i;
	matriz = (int**)malloc(sizeof(int*)*linhas);
	for (i = 0; i < linhas; i++)
		matriz[i] = (int*)malloc(sizeof(int)*colunas);
	return matriz;
}
/*
5. Crie uma função que recebe como parâmetros a matriz alocada dinamicamente, 
suas dimensões de linha e
coluna e proceda com a sua desalocação utilizando a função free
*/
int** questao5(int** matriz, int linhas, int colunas){
	
	if (linhas < 1 || colunas < 1)
		return NULL;
	int i;
	for (i = 0; i < linhas; i++)
		free(matriz[i]);
	matriz = NULL;
	return matriz;
}
/*
6. Crie uma função que receba uma matriz dinâmica como parâmetro e imprima a matriz completa.
*/
void questao6(int** matriz, int linhas, int colunas) {

	int i, j;
	for (i = 0; i < linhas; i++) {
		printf("|");
		for (j = 0; j < colunas; j++) {

			printf(" %d ", matriz[i][j]);
		}

		printf("|\n");
	}

}


int main() {

	int* vetor = questao1_alocar(10);
	vetor = questao1_desalocar(vetor,10);
//	questao3(vetor, 10);
	int** M = questao4(3, 2);
	questao6(M, 3, 2);


#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32

	return 0;
}
