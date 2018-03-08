

//O exercicio tem como objetivo exemplificar a aritmetica de ponteiros em c
#include<stdio.h>

void imprime_array_elemento(int* aArray, int iElemento) {
	printf("%d", *(aArray + iElemento));
}
void algoritmo_um_ponto_um(int* aArray) {

	int* Elemento1 = aArray;
	int* Elemento2= aArray+1;
	int* Elemento3 = aArray+2;
	int* Elemento4 = aArray+3;

	printf("\n___________\n");
	printf("Elemento1:%d\n", (*Elemento1));
	printf("Elemento2:%d\n", (*Elemento2));
	printf("Elemento3:%d\n", (*Elemento3));
	printf("Elemento4:%d\n", (*Elemento4));
	printf("___________\n");

}
int main() {
	int vetor[5] = { 10,20,30,40,50 };
	imprime_array_elemento(vetor,4);
	algoritmo_um_ponto_um(vetor);
	getchar();
	return 0;
}
