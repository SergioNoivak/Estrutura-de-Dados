#include<stdio.h>
#ifdef _WIN32
	#include<Windows.h>
#endif // _WIN32
#include<stdlib.h>
#include"ListaSequencial.h"

int main() {

	Lista* l =cria();
	struct aluno* al1 = malloc(sizeof(struct aluno));
	al1->matricula = 1;
	struct aluno* al2 = malloc(sizeof(struct aluno));
	al2->matricula = 2;
	struct aluno* al3 = malloc(sizeof(struct aluno));
	al3->matricula = 3;
	insere_lista_inicio(l, al1);
	insere_lista_inicio(l, al2);
	insere_lista_inicio(l, al3);
	



#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32
	return 0;
}
