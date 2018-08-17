#include<stdlib.h>
#include<stdio.h>
#ifdef WIN32
#include<Windows.h>
#endif // WIN32

#include<Windows.h>

#include"Heap.h"

int main()
{
	
	Heap* h = criar();
	Paciente* p1 =(Paciente*) malloc(sizeof(Paciente));
	p1->prioridade = 2;
	strcpy(p1->nome, "Adalberto");
	Paciente* p2 =(Paciente*) malloc(sizeof(Paciente));
	p2->prioridade = 3;
	strcpy(p2->nome, "Bertoldo");
	Paciente* p3 =(Paciente*) malloc(sizeof(Paciente));
	p3->prioridade = 1;
	strcpy(p3->nome, "Cassilda");

	Paciente* p4 = (Paciente*)malloc(sizeof(Paciente));
	p4->prioridade = 77;
	strcpy(p4->nome, "Cassilda");





	enfileirar(h, p3);

	enfileirar(h, p2);
	enfileirar(h, p1);
	enfileirar(h, p4);

	imprimir_vetor(h);

	desenfileirar(h);
	printf("\n");
	imprimir_vetor(h);

	desenfileirar(h);
	printf("\n");
	imprimir_vetor(h);
	desenfileirar(h);
	printf("\n");
	imprimir_vetor(h);
	desenfileirar(h);
	printf("\n");
	imprimir_vetor(h);

	desenfileirar(h);
	printf("\n");
	imprimir_vetor(h);


	//imprimir_vetor(h);
	




#ifdef WIN32
	system("PAUSE");

#endif // WIN32

	return 0;
}

