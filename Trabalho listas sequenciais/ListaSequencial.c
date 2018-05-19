#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencial.h"
#include<string.h>
#include<limits.h>




//   .........a) Crie o TAD de uma lista de alunos conforme descrito no livro disponibilizado no moodle...........

struct lista {
	int qtd;
	struct aluno dados[MAX];
};
//
// ..............b) Implemente uma fun��o que proceda com a aloca��o da lista. (Retorna o endere�o de aloca��o da lista
//conforme TAD descrito no cap�tulo 5 do livro disponibilizado no moodle).......
Lista* cria() {
	Lista* li = malloc(sizeof(Lista));
	if(li != NULL)
		li->qtd = 0;
	return li;
}

//......c) Desenvolva uma fun��o que proceda com a desaloca��o da Lista Sequencial 
//conforme discutido em sala...........

void libera_lista(Lista* li){
	free(li);
}

//........d) Desenvolver uma fun��o que receba uma lista como par�metro e retorne o tamanho da lista, sendo - 1 para
//lista n�o alocada..........

int tamanho_lista(Lista* li) {
	if (li == NULL)
		return -1;
	else
		return li->qtd;
}
//........e) Desenvolver uma fun��o que retorne 1 para lista cheia e 0 para lista n�o - cheia.Retornar - 1 para lista n�o
//alocada.............

int lista_cheia(Lista* li) {
	if (li == NULL)
		return - 1;
	return li->qtd == MAX;
}


//
//....f) Desenvolver uma fun��o que retorne 1 para lista vazia e 0 para lista n�o - vazia.Retornar - 1 para lista n�o
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

void exibe(Lista* l) {


	int i;
	for (i = 0; i < l->qtd; i++) {

		printf("{%d,%f,%f,%f,%s}\n ", l->dados[i].matricula, l->dados[i].n1, l->dados[i].n2, l->dados[i].n3, l->dados[i].nome);

	}
}


//
//...........g) Desenvolver uma fun��o que realize uma inser��o no in�cio da lista, ou seja, no �ndice 0 do vetor da lista.
//Caso a inser��o seja bem - sucedida retorne 1 e caso contr�rio retorne 0 (para lista cheia ou lista n�o
//	alocada).............
int insere_lista_inicio(Lista* li, struct aluno* al) {

	if (li == NULL)
		return -1;

	if (li->qtd == 0) {
		li->dados[0].matricula = al->matricula;
		li->dados[0].n1 = al->n1;
		li->dados[0].n2 = al->n2;
		li->dados[0].n3 = al->n3;
		strcpy(li->dados[0].nome,al->nome);
		li->qtd++;
		return 1;
	}


	li->qtd++;
	int i;
	for (i = li->qtd - 2; i >= 0; i--) {
		
		li->dados[i+1].matricula = li->dados[i].matricula;
		li->dados[i+1].n1 = li->dados[i].n1;
		li->dados[i+1].n2 = li->dados[i].n2;
		li->dados[i+1].n3 = li->dados[i].n3;
		strcpy(li->dados[i +1].nome, li->dados[i].nome);


	}

	li->dados[0].matricula = al->matricula;
	li->dados[0].n1 = al->n1;
	li->dados[0].n2 = al->n2;
	li->dados[0].n3 = al->n3;
	strcpy(li->dados[0].nome, al->nome);


	return 1;
}

//
//h) Desenvolver uma fun��o que realize uma inser��o no final da lista, ou seja, no �ndice subsequente ao
//�ltimo elemento do vetor da lista.Caso a inser��o seja bem - sucedida retorne 1 e caso contr�rio retorne 0.
//(para lista cheia ou lista n�o alocada).

int insere_lista_fim(Lista* li, struct aluno* al) {
	
	if (al == NULL||li->qtd==MAX)
		return 0;

	li->dados[li->qtd].matricula = al->matricula;
	li->dados[li->qtd].n1 = al->n1				;
	li->dados[li->qtd].n2=  al->n2				;
	li->dados[li->qtd].n3=  al->n3				;
	strcpy(li->dados[li->qtd].nome, al->nome);

	li->qtd++;
}
//
//i) Desenvolver uma fun��o que realize uma inser��o em uma posi��o da lista.Caso a posi��o esteja dentro
//da capacidade da lista e a mesma n�o est� cheia, proceda com a inser��o.Caso a inser��o seja bemsucedida
//retorne 1 e caso contr�rio retorne 0. (para lista cheia ou lista n�o alocada).

int insere_lista_meio(Lista* li, struct aluno* al,int pos) {

	if (pos < 0)
		return 0;
	if(li->qtd==0){
			li->dados[0].matricula = al->matricula;
			li->dados[0].n1 = al->n1;
			li->dados[0].n2 = al->n2;
			li->dados[0].n3 = al->n3;
			strcpy(li->dados[0].nome, al->nome);
			li->qtd++;
			return 1;

}

	else if (li->qtd == 1) {

		insere_lista_fim(li, al);
		return 1;



	}


	else if ( pos > li->qtd)
		return 0;


	li->qtd++;
	int i;
	for (i = li->qtd - 2; i >= pos; i--) {

		li->dados[i + 1].matricula = li->dados[i].matricula;
		li->dados[i + 1].n1 = li->dados[i].n1;
		li->dados[i + 1].n2 = li->dados[i].n2;
		li->dados[i + 1].n3 = li->dados[i].n3;
		strcpy(li->dados[i + 1].nome, li->dados[i].nome);
	}
	li->dados[pos].matricula = al->matricula;
	li->dados[pos].n1 = al->n1;
	li->dados[pos].n2 = al->n2;
	li->dados[pos].n3 = al->n3;
	strcpy(li->dados[pos].nome, al->nome);
}
int compare(struct aluno* a, struct aluno* b)
{
	if (a->matricula < b->matricula)
		return -1;
	return 1;

}

void ordenar(Lista* li) {
	qsort(li->dados, li->qtd, sizeof(struct aluno), compare);
}
//
//j) Desenvolver uma fun��o que realize uma inser��o ordenada por matr�cula na lista, 
//Caso a inser��o seja
//bem - sucedida retorne 1 e caso contr�rio retorne 0. (para lista cheia ou lista n�o alocada).
int insere_lista_ordenada(Lista* li, struct aluno* al) {
	insere_lista_fim(li, al);
	ordenar(li);
}

//k) Desenvolver Fun��o de remo��o no in�cio da Lista Sequencial.
void remover_inicio(Lista* li) {
	
	
	if (li == NULL || li->qtd == 0)
		return;


	if (li->qtd == 1) {
		li->qtd--;
		return;
	}
	
	
	int i;
	for (i = 1; i < li->qtd; i++) {
		li->dados[i - 1].matricula = li->dados[i].matricula;
		li->dados[i - 1].n1 =	  li->dados[i].n1;
		li->dados[i - 1].n2 = li->dados[i].n2;
		li->dados[i - 1].n3 = li->dados[i].n3;
		strcpy(li->dados[i - 1].nome, li->dados[i].nome);
	}

	li->qtd--;


}



void remover_fim(Lista* li) {

	if (li == NULL || li->qtd == 0)
		return;

		li->qtd--;
}

//m) Desenvolver Fun��o de Remo��o por valor da matr�cula.
void remover_via_matricula(Lista* li,int matricula) {

	int i;
	ordenar(li); //log2 n
	
	for (i = 0; i < li->qtd && li->dados[i].matricula != matricula; i++)
		continue; //n

	if (li->dados[i].matricula != matricula)
		return;

	li->dados[i].matricula = INT_MAX;
	ordenar(li); //log2 n
	li->qtd--;
	}

//n) Desenvolver Fun��o que realiza a remo��o de elementos por posi��o.

void remover_por_posicao(Lista* li, int posicao) {
	int i;

	if (posicao<0 || posicao>li->qtd - 1)
		return;
	
	ordenar(li); //log2 n
	li->dados[posicao].matricula = INT_MAX;
	ordenar(li); //log2 n
	li->qtd--;
}

//p) Desenvolver uma fun��o que realiza busca de elemento na lista sequencial por meio da posi��o do
//mesmo.Verificar se existe na lista uma determinada posi��o recebida como par�metro.Retornar 1 para
//posi��o existente e 0 para posi��o inexistente.////int existir_posicao(Lista* li, int posicao) {
//
//	if( posicao<0 || posicao>li->qtd-1)
//		return 0;  
//	return 1;
//}
//


//
//q) Desenvolver uma fun��o que realiza busca de elemento na lista sequencial de acordo com o seu conte�do.
//Verificar se existe na lista um elemento que possua um aluno com uma determinada matr�cula recebida
//como par�metro.Retornar 1 para posi��o existente e 0 para posi��o inexistente.


int existir_conteudo(Lista* li, struct aluno* al) {
	int i;
	for (i = 0; i < li->qtd; i++) 
		if (li->dados[i].matricula == al->matricula&&li->dados[i].n1 == al->n1 &&li->dados[i].n2 == al->n2 &&li->dados[i].n3 == al->n3) 
			if (strcmp(li->dados[i].nome, al->nome) == 0)
				return 1;
		   
	return 0;
}











