    /*1) Construa uma fun��o que recebe um vetor composto de 5 valores do tipo float como

par�metro e que imprime em tela os valores separados por 8 espa�os em branco. Na linha

seguinte deve apresentar apenas maior dos 5 elementos com uma precis�o de 5 casas

decimais ap�s a v�rgula.*/



#define TAM 5
#include<iostream>
using namespace std;

void setHe(float *myVector,int sizeofMyVector)
{

    for(int i=0; i<sizeofMyVector;i++)cin>>myVector[i];
}

void show(float *myVector, int sizeOfMyVector)
{

    for(int i=0; i<sizeOfMyVector;i++){
        cout<<myVector[i]<<"        ";
    }
    cout<<endl;
}

float moustBig(float *myVector,int sizeOfMyVector)
{
    float aux=myVector[0];
    for(int i=1; i<sizeOfMyVector;i++){
       if(aux<myVector[i])aux=myVector[i];
    }

    return aux;
}


int main(){



float *vet;
vet=new float[TAM];

//Entrada
setHe(vet,TAM);
show(vet,TAM);
float theBig;
theBig=moustBig(vet,TAM);
cout<<theBig;
return 0;

}
