// Programa ExFunFriend.cpp
// Exemplifica fun��es friends n�o-membros de classe

// Inclus�o das bibliotecas necess�rias
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// defini��o de constantes
const int STRMAX = 40;

// Defini��o da classe Pessoa
class Pessoa{
   private:
      char *nome;
      //friend int compara(const void *a, const void *b);
   public:
      //friend void saida(Pessoa *&, unsigned);
      Pessoa();
      void saida(){cout << "\n\t" << nome;}
      ~Pessoa(){delete[] nome;}
};

// Declara��o dos m�todos da classe Pessoa
Pessoa::Pessoa()
{
   char inbuf[STRMAX];
   cout << "\tNome: ";
   cin.get();
   cin.get(inbuf, STRMAX - 1);
   nome = new char[strlen(inbuf)-1];
   if (!nome) // testa o sucesso da aloca��o
   {
      cout << "Erro: Mem�ria insuficiente!\n";
      exit(0);
   }
   strcpy(nome, inbuf);
}

// Fun��es independentes (N�o-membros de classe)
int compara(const void *a, const void *b)
{
   Pessoa *primeiro = (Pessoa *) a;
   Pessoa *segundo = (Pessoa *) b;
   return(strcmp(primeiro->nome, segundo->nome));
}

void saida(Pessoa *&povo, unsigned total)
{
   qsort(povo, total, sizeof(povo[0]), compara);
   for (int i = 0; i < total; i++)
      povo[i].saida();
}

// Fun��o principal
int main()
{
   int total = 0;
   cout << "Total de pessoas: ";
   cin >> total;
   cout << endl;
   Pessoa *povo = new Pessoa[total]; // aloca o vetor dinamicamente
   cout << endl << "\nVetor ordenado em ordem alfabetica:\n";
   saida(povo, total);
   cout << endl << "\nExecucao terminada\n" << endl;
   delete[] povo;
   return 0;
}
