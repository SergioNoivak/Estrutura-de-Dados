#pragma once
#define MAX 1023
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct Heap Heap;
typedef struct Paciente{

	int prioridade;
	char nome[200];

}Paciente;

Heap* criar();
void liberar(Heap** heap);
int tamanho_heap(Heap* heap);
int heap_cheia(Heap* heap);
int heap_vazia(Heap* heap);
void copiar(Paciente* destino, Paciente* origem);
void swap(Paciente* p1, Paciente* p2);
int esta_na_faixa(int indice);
void promover(Heap* heap, int filho);
void enfileirar(Heap* heap, Paciente* paciente);
int desenfileirar(Heap* heap);
void imprimir_vetor(Heap* heap);