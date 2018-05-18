#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencial.h"
#include<string.h>
//   .........a) Crie o TAD de uma lista de alunos conforme descrito no livro disponibilizado no moodle...........
struct lista {
	int qtd;
	struct aluno dados[MAX];
};
//
// ..............b) Implemente uma função que proceda com a alocação da lista. (Retorna o endereço de alocação da lista
//conforme TAD descrito no capítulo 5 do livro disponibilizado no moodle).......
Lista* cria() {
	Lista* li = malloc(sizeof(Lista));
	if(li != NULL)
		li->qtd = 0;
	return li;
}

//......c) Desenvolva uma função que proceda com a desalocação da Lista Sequencial //conforme discutido em sala...........
void libera_lista(Lista* li){
	free(li);
}

//........d) Desenvolver uma função que receba uma lista como parâmetro e retorne o tamanho da lista, sendo - 1 para
//lista não alocada..........
int tamanho_lista(Lista* li) {
	if (li == NULL)
		return -1;
	else
		return li->qtd;
}
//........e) Desenvolver uma função que retorne 1 para lista cheia e 0 para lista não - cheia.Retornar - 1 para lista não
//alocada.............
int lista_cheia(Lista* li) {
	if (li == NULL)
		return - 1;
	return li->qtd == MAX;
}


//
//....f) Desenvolver uma função que retorne 1 para lista vazia e 0 para lista não - vazia.Retornar - 1 para lista não
//alocada.....
int lista_vazia(Lista* li) {
	if (li == NULL)
		return -1;
	return li->qtd == 0;
}


int busca_lista_pos(Lista* li, int pos, struct aluno* al) {

	if (li == NULL || pos <= 0 || pos > li->qtd)
		return;
	*al = li->dados[pos - 1];
	return 1;
}
int busca_lista_mat(Lista* li, int mat, struct aluno* al) {
	if (li == NULL)
		return 0;
	int i;
	for (i = 0; i < li->qtd; i++) {
		if (li->dados[i].matricula == mat) {
			*al = li->dados[i];
			return 1;
		}
	}
	return 0;
}

//
//...........g) Desenvolver uma função que realize uma inserção no início da lista, ou seja, no índice 0 do vetor da lista.
//Caso a inserção seja bem - sucedida retorne 1 e caso contrário retorne 0 (para lista cheia ou lista não
//	alocada).............
int insere_lista_inicio(Lista* li, struct aluno* al) {

	if (li == NULL)
		return -1;

	if (li->qtd == 0) {
		li->dados[0] = *al;
		li->qtd++;
		return 1;
	}

	struct aluno aux;
	int i=0;


	li->qtd++;
	for (i = 0; i < li->qtd - 1; i++) {

		li->dados[i + 1].matricula = li->dados[i].matricula;
		li->dados[i + 1].n1 = li->dados[i].n1;
		li->dados[i + 1].n2 = li->dados[i].n2;
		li->dados[i + 1].n3 = li->dados[i].n3;
		strcpy(li->dados[i + 1].nome ,li->dados[i].nome);

		aux.matricula = li->dados[i+1].matricula;
		aux.n1 = li->dados[i+1].n1;
		aux.n2 = li->dados[i+1].n2;
		aux.n3 = li->dados[i+1].n3;
		strcpy(aux.nome, li->dados[i+1].nome);

		
	}


	for (i = 0; i < li->qtd - 1; i++) {
	
		printf("%d ", li->dados[i].matricula);
	
	}



	return 0;
}
