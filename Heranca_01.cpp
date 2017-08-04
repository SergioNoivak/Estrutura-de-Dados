
/* Aqui temos um exemplo de Heranca em C++ */

#include<iostream>
#include<string>
using namespace std;
 class pessoa{
 int saldo=0;
 };

 class Funcionario{


    protected:
        string Nome;
        string Sobrenome;
        string Categoria;
        int Codigo;
        string CPF;
        int tempoDeEmpresa;
        float salarioBase;
        float salarioFinal;
        int numeroDeFilhos;

 };
 0 : public Funcionario{
protected:
  string CNH;
  string veiculo;
  string origem;
  string destino;
public:
    Motorista(){ ///muda valor padrão
                CNH.erase(0, CNH.length());
                veiculo.erase(0,veiculo.length());
                origem.erase(0,origem.length());
                destino.erase(0,destino.length());}

  };

class responsavelDeEstoque : public Funcionario{
    protected:
        bool gerenciarQuantEstoque;
    public:
        responsavelDeEstoque(){gerenciarQuantEstoque=true;}
};

class Vendedor : public Funcionario{
protected:
    bool atenderOsClientes;
    bool efetuarVenda;
public:
    Vendedor(){ atenderOsClientes=true;
                efetuarVenda=true;}
};

class Gerente : public Funcionario{
    protected:
        bool cuidarDaEmpresaComoUmTodo;
    public:
        Gerente(){cuidarDaEmpresaComoUmTodo=true; }
};


using namespace std;

int main(){





}
