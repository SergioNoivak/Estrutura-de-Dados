#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include<string.h>

typedef struct elemento {
	Aluno dados;
	Lista *prox;
}Lista;

Lista** lista_cria() {
	Lista** li = (Lista**)malloc(sizeof(Lista*));
	if (li != NULL)
		*li = NULL; //coloca a lista como vazia
	return li;
}

int lista_libera(Lista** pLista) {
	if (pLista == NULL)return 0;
	if (*pLista == NULL)
		/*Lista Vazia - Ponteiro para a lista pode ser liberado*/
		free(pLista);
	return 1;

}

//b) Verificação se a lista está vazia.
int is_vazia(Lista** pLista) {
	
	if (pLista == NULL)
		return 1;
	if (*pLista == NULL)
		return 1;
	return 0;
}


Aluno* entrada_dados_aluno(int matricula, char nome[40], float n1, float  n2, float  n3) {

	Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
	aluno->matricula = matricula;
	strcpy(aluno->nome, nome);
	aluno->n1 = n1;
	aluno->n2 = n2;
	aluno->n3 = n3;
	return aluno;
}


//h) Função de inserção de nós no início da lista
void insere_inicio(Lista** pLista,Aluno* aluno) {
	
	if (pLista == NULL)
		return;
	struct elemento* elemento = (struct elemento*) malloc(sizeof(struct elemento));
	
	if (elemento == NULL)
		return;

	elemento->prox = *pLista;
	*pLista = elemento;
	elemento->dados.matricula = aluno->matricula;
	elemento->dados.n1 = aluno->n1;
	elemento->dados.n2 = aluno->n2;
	elemento->dados.n3= aluno-> n3;
	strcpy(elemento->dados.nome, aluno->nome);
}


void insere_fim(Lista** pLista, Aluno* aluno) {

	if (pLista == NULL)
		return;
	struct elemento* elemento = (struct elemento*) malloc(sizeof(struct elemento));

	if (elemento == NULL)
		return;

	struct elemento* i;
	if (*pLista == NULL) {
		insere_inicio(pLista, aluno);
		return;
	}
	for (i = *pLista; i->prox != NULL ; i = i->prox)
		continue;

	i->prox= elemento;
	elemento->dados.matricula = aluno->matricula;
	elemento->dados.n1 = aluno->n1;
	elemento->dados.n2 = aluno->n2;
	elemento->dados.n3 = aluno->n3;
	strcpy(elemento->dados.nome, aluno->nome);
	elemento->prox = NULL;
}

//j) Função que realiza a inserção de elementos por posição.A função deverá verificar se a posição existe na
//lista e em caso afirmativo, proceder com a inserção.


void insere_posicao(Lista** pLista, Aluno* aluno, int posicao) {

	if (pLista == NULL || posicao < 0)
		return;
	
	struct elemento* elemento = (struct elemento*) malloc(sizeof(struct elemento));

	Lista* i;
	int contador_posicoes = 0;
	for (i = *pLista; i != NULL; i = i->prox,contador_posicoes++) {
		
		if (contador_posicoes == posicao) {

			Lista* aux = i->prox;
			i->prox = elemento;
			elemento->dados.matricula = aluno->matricula;
			elemento->dados.n1 = aluno->n1;
			elemento->dados.n2 = aluno->n2;
			elemento->dados.n3 = aluno->n3;
			strcpy(elemento->dados.nome, aluno->nome);
			elemento->prox = aux;
			return;
		}

		
	}





}


void exibir_aluno(Aluno* aluno) {

	printf("\n{matricula:%d, n1:%f , n2:%f , n3:%f, nome:%s }", aluno->matricula, aluno->n1, aluno->n2, aluno->n3, aluno->nome);
}
void exibir_recursivo(Lista* inicial) {

	if (inicial == NULL) {

		printf("NULL");

		return;
	}

	exibir_aluno(&(inicial->dados));
	printf("->");
	exibir_recursivo(inicial->prox);

}





