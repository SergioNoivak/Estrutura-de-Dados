#include<stdio.h>
#include<stdlib.h>
#include"filaPrioridades.h"




struct filaPrioridade {
	int qtd;
	int inicio;
	int fim;
	struct Aeronave dados[MAX];


};

FilaPrio* fila_cria() {

	FilaPrio* fila;
	fila = (FilaPrio*)malloc(sizeof(FilaPrio));
	if (fila != NULL) {
		fila->qtd = 0;
		fila->inicio=-1;
		fila->fim   =-1;
	}
	return fila;
}

void fila_libera(FilaPrio** f) {
	free(*f);
	*f = NULL;
}

int fila_vazia(FilaPrio* f) {

	return f == NULL ? -1 : f->qtd == 0 ? 1 : 0;
}
int fila_cheia(FilaPrio* f) {

	return f == NULL ? -1 : f->qtd == MAX ? 1 : 0;
}

int fila_tamanho(FilaPrio* f) {
	return f->qtd;
}

void fila_exibir(FilaPrio* f) {

	int i;
	for (i = 0; i < f->qtd; i++) 
		printf(" %d ", f->dados[(f->inicio + i) % MAX].qtdCombustivel);
}






void elemento_copiar(struct Aeronave* destination, struct Aeronave* source) {

	destination->codAeronave =    source->codAeronave;
	destination->numvoo =         source->numvoo;
	destination->qtdCombustivel = source->qtdCombustivel;
}



void fila_insere(FilaPrio* f,struct Aeronave* a) {

	//caso vazia 
	if (f->fim  == -1 && f->inicio==-1) {
		printf("caso vazia ");

		f->qtd++;
		f->inicio = f->fim = f->qtd - 1;

		f->dados[(f->inicio)].qtdCombustivel = a->qtdCombustivel;
		elemento_copiar(&f->dados[(f->inicio)], a);
		return;
	}

	//caso inserir no inicio
	if (f->dados[f->inicio].qtdCombustivel > a->qtdCombustivel) {
		printf("caso inserir no inicio");
		int indice_antes_do_inicio = (f->inicio + f->qtd) % MAX +(MAX-1 - f->qtd);
		elemento_copiar( &f->dados[indice_antes_do_inicio],a);
		f->inicio = indice_antes_do_inicio;
		f->qtd++;
		return;
	}

	int i;
	int inserir_meio = 0;

	for (i = 0; i < f->qtd; i++) {

		if (f->dados[(f->inicio + i) % MAX].qtdCombustivel > a->qtdCombustivel) {
			inserir_meio = 1;
			break;
		}
	}
	if (inserir_meio) {

		struct Aeronave auxiliar;
		struct Aeronave swap;

		elemento_copiar(&auxiliar, &f->dados[(f->inicio + i) % MAX]);
		int j;
		for (j = i; j < f->qtd + 1; j++) {

			elemento_copiar(&swap, &f->dados[(f->inicio + j+1) % MAX]);
			elemento_copiar(&f->dados[(f->inicio + j + 1) % MAX],&auxiliar);
			elemento_copiar(&auxiliar,&swap);
		}
		elemento_copiar(&f->dados[(f->inicio + i) % MAX],a);
		f->qtd++;
	}
	else {
			elemento_copiar(&f->dados[(f->inicio + f->qtd) % MAX], a);
			f->fim = (f->inicio + f->qtd) % MAX;
			f->qtd++;
	}
}



