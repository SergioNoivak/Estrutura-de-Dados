#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include<string.h>

typedef struct elemento {
	Aluno dados;
	Lista *prox;
}Lista;


Lista** lista_cria() {
	Lista** li = (Lista**)malloc(sizeof(Lista*));
	if (li != NULL)
		*li = NULL; //coloca a lista como vazia
	return li;
}

int lista_libera(Lista** pLista) {
	if (pLista == NULL)return 0;
	if (*pLista == NULL)
		/*Lista Vazia - Ponteiro para a lista pode ser liberado*/
		free(pLista);
	return 1;

}

//b) Verificação se a lista está vazia.
int is_vazia(Lista** pLista) {
	
	if (pLista == NULL)
		return 1;
	if (*pLista == NULL)
		return 1;
	return 0;
}

//h) Função de inserção de nós no início da lista
void insere_inicio(Lista** pLista, ) {
	
	
	struct elemento* elemento = (struct elemento*) malloc(sizeof(struct elemento));

	if (elemento == NULL)
		return;
	if (pLista == NULL)
		return;

	elemento->prox = *pLista;
	*pLista = elemento;
}












void entrada_dados_aluno(int matricula, char nome[40], float n1, float  n2, float  n3) {

	Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
	aluno->matricula = matricula;
	strcpy(aluno->nome, nome);
	aluno->n1 = n1;
	aluno->n2 = n2;
	aluno->n3 = n3;
}









