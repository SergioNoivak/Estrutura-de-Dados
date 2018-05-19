#include<stdio.h>
#ifdef _WIN32
	#include<Windows.h>
#endif // _WIN32
#include<stdlib.h>
#include"ListaSequencial.h"

int main() {

	Lista* lista =cria();
	struct aluno* aluno1 = malloc(sizeof(struct aluno));
	aluno1->matricula = 3;
	aluno1->n1 = 1.1;
	aluno1->n2 = 1.1;
	aluno1->n3 = 1.1;
	strcpy(aluno1->nome, "Adsad");
	struct aluno* al2 = malloc(sizeof(struct aluno));
	al2->matricula = 2;
	al2->n1 = 1.1;
	al2->n2 = 1.1;
	al2->n3 = 1.1;
	strcpy(al2->nome, "Adsad");
	struct aluno* al3 = malloc(sizeof(struct aluno));
	al3->matricula = 1;
	al3->n1 = 1.1;
	al3->n2 = 1.1;
	al3->n3 = 1.1;
	strcpy(al3->nome, "Adsad");
    insere_lista_ordenada(lista, aluno1);
    insere_lista_ordenada(lista, al3);
    insere_lista_ordenada(lista, al2);
	exibe(lista);

	printf("%d", existir_conteudo(lista, aluno1));


	
#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32
	return 0;
}
