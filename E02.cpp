/*2) Construa uma fun��o que receba como par�metros dois valores inteiros. O primeiro

deve ser passado por refer�ncia, enquanto o segundo por c�pia. Demonstre fora da fun��o

os endere�os dos dois elementos passados por par�metro e em seguida apresente os

endere�os dos par�metros de entrada dentro da fun��o. Que caracter�stica foi observada

com rela��o aos endere�os apresentados?*/



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
