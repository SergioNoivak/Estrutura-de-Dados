    /*5) Considere que você trabalha em uma empresa que precisa fazer o controle de contas bancárias dos clientes.
     Implemente uma classe responsável por armazenas as informações de cada cliente.
      Sabe-se, a priori, que cada pessoa tem registrado o Nome, CPF, Telefone, Número da Agencia e Conta,
    Saldo disponível, Estado civil, o tempo em que é cliente do banco e se alguma vez já foi premiado
    pela agência
    a) Os atributos da classe devem ser private;
        b) Implemente um construtor default que “zere”
        os campos de um objeto da classe no momento em que ele é criado;
            c) Construa um construtor por cópia que permita ao gerente do banco
            fazer a geração de um novo objeto carregando os dados de um cliente já existente;
                d) Implemente uma função friend GetSaldo que, quando passado um
                objeto por parâmetro, retorne o valor do saldo da conta armazenada;
                    e) Implemente uma função membro da classe criada chamada Deposita
                    que receba um valor float por parâmetro e atualize o saldo disponível na conta;*/





#include<iostream>
using namespace std;


///classe dinheiro
class Money{
        private:
            float valor;
        public:
            float getMoney(){return valor;}///Pega o valor
            void eraseValue(){valor=0.0;}///Apaga o valor
            void setValue(int newValue){valor=newValue;}///muda valor
};

///classe DATA dd/mm/aa
class Date{
    private:
        int dd;
        int mm;
        int aa;
    };

void eraseValue(string &texto){


    texto.erase(0,texto.length());
}


void eraseValue(Money &dinheiro){
    dinheiro.eraseValue();
}

template<class T>
void eraseValue(T &valor){
    valor=0;
}

class Cliente{
    private:
        string Nome;
        string CPF;
        string Telefone;
        int NumerodaAgencia;
        int NumerodaConta;
        Money SaldoDisponivel;
        string EstadoCivil;
        string tempoNaEmpresa;
        bool premiado;
    public:
        Cliente();
        Cliente(Cliente &outro);
        string getNome(){return Nome;}
        string getCPF(){return CPF;}
        string getTelefone(){return Telefone;}
        int getNumerodaAgencia(){return NumerodaAgencia;}
        int getNumerodaConta(){return NumerodaConta;}
        string getEstadoCivil(){return EstadoCivil;}
        string getTempoNaEmpresa(){return tempoNaEmpresa;}
        bool getPremiado(){return premiado;}
        friend


    };




///Construtor que muda DEFAULT/PADRão
Cliente::Cliente(){

    eraseValue(Nome);///Nome=""
    eraseValue(CPF);
    eraseValue(Telefone);
    eraseValue(NumerodaAgencia);
    eraseValue(NumerodaConta);
    eraseValue(SaldoDisponivel);
    eraseValue(EstadoCivil);
    eraseValue(tempoNaEmpresa);
    eraseValue(premiado);
}


///Construtor de copia
Cliente::Cliente(Cliente &outro){
   Nome=outro.getNome();
   CPF=outro.getCPF();
   Telefone=outro.getTelefone();
   NumerodaAgencia=outro.getNumerodaAgencia();
   NumerodaConta=outro.getNumerodaConta();



}

int main()
{

 Cliente eu;




}
