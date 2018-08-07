#pragma once
#ifndef FILAPRIORIDADES_H
#define FILAPRIORIDADES_H
#define MAX 100
struct Aeronave {
	int numvoo;
	int codAeronave;
	int qtdCombustivel;
};
typedef struct filaPrioridade FilaPrio;
FilaPrio* fila_cria();
void fila_libera(FilaPrio** f);
int fila_vazia(FilaPrio* f);
int fila_cheia(FilaPrio* f);
int fila_tamanho(FilaPrio* f);
void fila_insere(FilaPrio* f, struct Aeronave* a);
void fila_exibir(FilaPrio* f);
#endif // !FILAPRIORIDADES_H
