#include<stdio.h>
#include"filaPrioridades.h"
#ifdef _WIN32
	#include<Windows.h>
#endif

int main()
{

	FilaPrio* f = fila_cria();
	//fila_libera(p);

	struct Aeronave* a = malloc(sizeof(struct Aeronave));
	a->qtdCombustivel = 1;
	struct Aeronave* b = malloc(sizeof(struct Aeronave));
	b->qtdCombustivel = 01;
	struct Aeronave* c = malloc(sizeof(struct Aeronave));
	c->qtdCombustivel = -111;
	struct Aeronave* d = malloc(sizeof(struct Aeronave));
	d->qtdCombustivel = 7;


	struct Aeronave* e = malloc(sizeof(struct Aeronave));
	e->qtdCombustivel = 88;
	fila_insere(f, a);
	fila_insere(f, b);
	fila_insere(f, c);
	fila_insere(f, d);
	fila_insere(f, e);
	fila_exibir(f);
	printf(" TAM: %d", fila_tamanho(f));


#ifdef _WIN32
	system("pause");
#endif

	return 0;
}

