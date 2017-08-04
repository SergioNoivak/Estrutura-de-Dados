/*2) Construa uma função que receba como parâmetros dois valores inteiros. O primeiro

deve ser passado por referência, enquanto o segundo por cópia. Demonstre fora da função

os endereços dos dois elementos passados por parâmetro e em seguida apresente os

endereços dos parâmetros de entrada dentro da função. Que característica foi observada

com relação aos endereços apresentados?*/



#include<iostream>
using namespace std;

void func(int &valorRef, int valorCopy)
{
    valorCopy++;
    valorRef++;

}



int main(){


        int valor1=0, valor2=0;

        func(valor1,valor2);
        cout<<"valor por referencia : "<<valor1<<endl<<"valor por copia: "<<valor2;
        return 0;
}
