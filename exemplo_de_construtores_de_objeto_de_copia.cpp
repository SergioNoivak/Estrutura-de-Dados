// Programa ExFunFriend.cpp
// Exemplifica funções friends não-membros de classe

// Inclusão das bibliotecas necessárias
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// definição de constantes
const int STRMAX = 40;

// Definição da classe Pessoa
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

// Declaração dos métodos da classe Pessoa
Pessoa::Pessoa()
{
   char inbuf[STRMAX];
   cout << "\tNome: ";
   cin.get();
   cin.get(inbuf, STRMAX - 1);
   nome = new char[strlen(inbuf)-1];
   if (!nome) // testa o sucesso da alocação
   {
      cout << "Erro: Memória insuficiente!\n";
      exit(0);
   }
   strcpy(nome, inbuf);
}

// Funções independentes (Não-membros de classe)
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

// Função principal
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
