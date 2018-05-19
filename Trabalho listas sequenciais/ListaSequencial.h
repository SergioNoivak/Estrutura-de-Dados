#pragma once
#define MAX 100
struct aluno {
	int matricula;
	char nome[30];
	float n1, n2, n3;
};
typedef struct lista Lista;

Lista* cria();
void libera_lista(Lista* li);
int busca_lista_pos(Lista* li, int pos, struct aluno* al);
int busca_lista_mat(Lista* li, int pos, struct aluno* al);
int insere_lista_final(Lista* li, struct aluno* al);
int insere_lista_inicio(Lista* li, struct aluno* al);
int insere_lista_ordenada(Lista* li, struct aluno* al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void ordenar(Lista* );
//
//j) Desenvolver uma função que realize uma inserção ordenada por matrícula na lista, 
//Caso a inserção seja
//bem - sucedida retorne 1 e caso contrário retorne 0. (para lista cheia ou lista não alocada).
int insere_lista_ordenada(Lista* , struct aluno* );
//k) Desenvolver Função de remoção no início da Lista Sequencial.
void remover_inicio(Lista* );

void remover_fim(Lista* );
//m) Desenvolver Função de Remoção por valor da matrícula.
void remover_via_matricula(Lista* , int );








