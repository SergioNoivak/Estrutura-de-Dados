#include<stdio.h>
#ifdef _WIN32
#include<Windows.h>
#endif // _WIN32
#include<stdlib.h>
/*
1.Crie uma função em C que receba como parâmetro o endereço de uma struct nascimento declarada
estaticamente na função main e preencha seus valores retornando 1 para sucesso e 0 para insucesso.
A função
só deverá proceder com o preenchimento dos valores se o endereço da struct informada não for nulo.
A struct global nascimento deverá conter os atributos abaixo :
*/
enum estados{
	fracasso = 0,
	sucesso = 1
};
struct pessoa {
	int dia;
	int mes;
	int ano;
};
int questao01(struct pessoa* p) {
	if (p == NULL)
		return fracasso;
	printf("\n Item dia:");
	fflush(stdin);
	scanf("%d", &(p->dia));
	printf("\n Item mes:");
	fflush(stdin);
	scanf("%d", &(p->mes));
	printf("\n Item ano:");
	fflush(stdin);
	scanf("%d", &(p->ano));
	return sucesso;
}
/*
2. Crie uma função em C que realize a alocação dinâmica de uma struct igual
à mostrada na figura do exercício
anterior, preenchendo com 0 os valores de dia,
mês e ano, retornando para a chamada da função o endereço do
bloco alocado;
*/

void questao02_subprograma_preenche_com_zero(struct pessoa* pessoa_de_retorno) {
	pessoa_de_retorno->ano = pessoa_de_retorno->dia = pessoa_de_retorno->mes = 0;
}
struct pessoa* questao02() {
	struct pessoa* pessoa_de_retorno =  (struct pessoa*) malloc(sizeof(struct pessoa));
	questao02_subprograma_preenche_com_zero(pessoa_de_retorno);
	return pessoa_de_retorno;
}

/*
3. Crie um exemplo de utilização da função criada no exercício 01, recebendo como parâmetro o endereço da
struct alocada dinamicamente no exercício 2;
*/
struct pessoa* questao03() {
	struct pessoa* pessoa_de_retorno = questao02();
	questao01(pessoa_de_retorno);
	return pessoa_de_retorno;
}
/*
4. Crie uma função que aloque dinamicamente um vetor de structs 
do tipo utilizado nos exercícios anteriores,
preenchendo com 0 todos os seus valores de atributos e retornado 
o endereço do vetor alocado.O tamanho do
vetor deverá ser armazenado na função main e recebido via parâmetro da função 
por meio de um ponteiro para
inteiro.
*/
struct pessoa* questao04(int tamanho_de_vetor) {
	struct pessoa* vetor_de_pessoas = (struct pessoa*) malloc(sizeof(struct pessoa)*tamanho_de_vetor);
	int i;
	for(i=0;i<tamanho_de_vetor;i++)
	questao02_subprograma_preenche_com_zero(&(vetor_de_pessoas[i]));
	return vetor_de_pessoas;
}
/*
5. Crie uma função que receba como parâmetro o tamanho do vetor de structs, assim como o endereço desta
struct (verificando se o endereço não é NULL) e proceda 
com o preenchimento dos dados de cada struct do
	vetor.Durante o preenchimento, utilize um laço de repetição que percorra o vetor realizando chamadas à
	função criada no exercício 1. Ao final a função deverá retornar 1 para sucesso e 0 para insucesso.
	*/

int questao05(int tamanho_do_vetor, struct pessoa* vetor) {
	if (vetor == NULL)
		return fracasso;
	int estado = sucesso;
	int i;
	for (i = 0; i < tamanho_do_vetor; i++) {
		estado = questao01(&(vetor[i]));
		if (estado != sucesso)
			return fracasso;
	}
	return sucesso;
}


int main() {
	/*struct pessoa pessoa_da_questao1;
	questao01(&pessoa_da_questao1);
*/
/*
	struct pessoa* pessoa_questao2 = questao03();
	printf("[%d, %d, %d]", pessoa_questao2->dia, pessoa_questao2->ano, pessoa_questao2->mes);

*/

	/*struct pessoa* vetor = questao04(5);
	int i = 0;
	for(i=0;i<5;i++)
		printf("[%d, %d, %d]", vetor[i].dia, vetor[i].ano, vetor[i].mes);

	printf("\n");
	questao05(5, vetor);
*/

#ifdef _WIN32
	system("PAUSE");
#endif // _WIN32

	return 0;
}
