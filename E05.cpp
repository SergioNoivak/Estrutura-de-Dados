/*4) Construa uma fun��o template que receba como par�metro um vetor composto
    de elementos de um tipo do qual ela (a fun��o)
    n�o conhece e tamb�m um valor int que indique o tamanho do vetor.
     A fun��o dever� exibir na tela o maior e menor elementos presentes no vetor.*/

#include<iostream>
using namespace std;

template <class T>
void setVector(T* v, int sizeOfV)
{
    for(int i=0; i<sizeOfV; i++)cin>>v[i];
}

template <class T>
void showVector(T* v, int sizeOfV)
{

    for(int i=0; i<sizeOfV; i++)
        cout<<endl<<v[i];
}

template<class T, class myTypeOne, class myTypeTwo>
void moustBigAndMoustSmall(T* v,int sizeOfV,myTypeOne &bigVar,myTypeTwo &smallVar)
{
    bigVar=v[0];
    smallVar=v[0];
    for(int i=1; i<sizeOfV; i++)
    {
        if(bigVar<v[i])
            bigVar=v[i];
        if(smallVar>v[i])
            smallVar=v[i];
    }
}

int main()
{    

    int *vetor, sizeOfVetor;
    cin>>sizeOfVetor;
    vetor=new int[sizeOfVetor];
    setVector(vetor,sizeOfVetor);
    int theBig,theSmall;
    moustBigAndMoustSmall(vetor,sizeOfVetor,theBig,theSmall);
    cout<<endl<<"O maior: "<<theBig<<endl<<"O menor: "<<theSmall;
    return 0;
}
