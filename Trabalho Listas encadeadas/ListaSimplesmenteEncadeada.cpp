
#include "stdafx.h"
#include"No.h"
#include<stdlib.h>
#ifdef _WIN32
#include<Windows.h>
#endif



int main()
{
	Lista** lista = lista_cria();
	Aluno* al = entrada_dados_aluno(1, "Edson", 1.1, 1.2, 1.3);
	Aluno* al2 = entrada_dados_aluno(1, "Edson2", 2.1, 2.2, 2.3);
	Aluno* al3 = entrada_dados_aluno(1, "Edson3", 3.1, 3.2, 3.3);
	Aluno* al4 = entrada_dados_aluno(1, "Edson4", 4.1, 4.2, 4.3);

	Aluno* alx = entrada_dados_aluno(1, "Edsonx", 2.1, 2.2, 2.3);

	insere_fim(lista, al);
	insere_fim(lista, al2);
	insere_fim(lista, al3);
	insere_fim(lista, al4);
	exibir_recursivo(*lista);


	insere_posicao(lista, alx, 4);
	printf("\n \n");
	exibir_recursivo(*lista);

#ifdef _WIN32
	system("PAUSE");
#endif

	
	
	return 0;
}
