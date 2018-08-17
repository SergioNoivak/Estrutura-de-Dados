#include"Heap.h"
struct Heap {
	Paciente dados[MAX];
	int qtd;
};

Heap* criar() {

	Heap* heap = (Heap*)malloc(sizeof(Heap));
	
	if (heap == NULL)
		return NULL;
	
	heap->qtd = 0;
	return heap;
}
void liberar(Heap** heap) {

	free(*heap);
	*heap = NULL;
}

int tamanho_heap(Heap* heap) {

	return heap == NULL ? -1 : heap->qtd;

}

int heap_cheia(Heap* heap) {

	return heap == NULL ? -1 : heap->qtd==MAX? 1:0;
}

int heap_vazia(Heap* heap) {

	return heap == NULL ? -1 : heap->qtd == 0 ? 1 : 0;
}

void copiar(Paciente* destino, Paciente* origem) {

	strcpy(destino->nome, origem->nome);
	destino->prioridade = origem->prioridade;
}

void swap(Paciente* p1, Paciente* p2) {

	Paciente paux;
	copiar(&paux, p1);
	copiar(p1, p2);
	copiar(p2, &paux);
}


int esta_na_faixa(int indice) {

	return indice > 0 && indice < MAX ? 1 : 0;

}


void promover(Heap* heap, int filho) {
	if (filho == 0)
		return;

	int pai = (filho - 1) / 2;
	char nome_aux[200];
	int prioridade_aux;

	while (filho > 0 && heap->dados[filho].prioridade >=  heap->dados[pai].prioridade) {
		swap(&heap->dados[filho],&heap->dados[pai]);
		filho = pai;
		pai = (pai - 1) / 2;
	}
}

void enfileirar(Heap* heap,Paciente* paciente) {

	copiar(&heap->dados[heap->qtd], paciente);
	promover(heap, heap->qtd);
	heap->qtd++;
}

void imprimir_vetor(Heap* heap) {

	int i;
	if (heap->qtd == 0) {
		printf("Heap vazia");
		return;
	}
	for (i = 0; i < heap->qtd; i++)
		printf(" %d ", heap->dados[i].prioridade);
}


int possui_irmao_direito(Heap* heap,int elemento) {
	return elemento < heap->qtd - 1;
}

int maior_prioridade(Heap* heap ,int irmao_esquerdo, int irmao_direito){

	return heap->dados[irmao_esquerdo].prioridade > heap->dados[irmao_direito].prioridade ? irmao_esquerdo : irmao_direito;
}




void rebaixar(Heap* heap, int pai) {
	
	int filho_em_destaque = pai * 2 + 1;
	while (esta_na_faixa(filho_em_destaque)) {
		if (possui_irmao_direito(heap, filho_em_destaque)) 
			filho_em_destaque = maior_prioridade(heap,filho_em_destaque, filho_em_destaque + 1);

		if (heap->dados[filho_em_destaque].prioridade < heap->dados[pai].prioridade)
			break;

		swap(&heap->dados[filho_em_destaque], &heap->dados[pai]);

		pai = filho_em_destaque;
		filho_em_destaque = pai * 2 + 1;
	}
}


int desenfileirar(Heap* heap) {

	if (heap == NULL)
		return -1;

	if (heap->qtd == 1) {
		heap->qtd--;
		return 0;
	}

	if (heap_vazia(heap))
		return 0;

	copiar(&heap->dados[0], &heap->dados[heap->qtd-1]);
	heap->qtd--;
	rebaixar(heap, 0);

	return 1;
}



