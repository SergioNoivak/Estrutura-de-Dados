#ifndef NO_H
#define NO_H

typedef struct aluno {
	int matricula;
	char nome[40];
	float n1, n2, n3;
}Aluno;

typedef struct elemento Lista;

Lista** lista_cria();
int lista_libera(Lista** li);



//Funcoes auxiliares




#endif 

