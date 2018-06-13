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
void insere_inicio(Lista** pLista, struct elemento* elemento);
int is_vazia(Lista** pLista);

//b) Verifica��o se a lista est� vazia.
int is_vazia(Lista** pLista);
Aluno*  entrada_dados_aluno(int matricula, char nome[40], float n1, float  n2, float  n3);
//h) Fun��o de inser��o de n�s no in�cio da lista
void insere_inicio(Lista** pLista, Aluno* aluno);
void exibir_aluno(Aluno* aluno);
void exibir_recursivo(Lista* inicial);
void insere_posicao(Lista** pLista, Aluno* aluno, int posicao);


//Funcoes auxiliares




#endif 

