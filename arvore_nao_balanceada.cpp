

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <math.h>


using namespace std;

typedef
struct No{
int value;
struct No* e;
struct No* d;
}No;


void criar_arvore(No** arvore){

    (*arvore)=NULL;
}

void inserir(No **arvore, int chave){
    if(*arvore==NULL){
        (*arvore) = new No();
        (*arvore)->e=NULL;
        (*arvore)->d=NULL;
        (*arvore)->value=chave;
    }
    else{
        if(chave<(*arvore)->value)
            inserir(&(*arvore)->e,chave);
        if(chave>(*arvore)->value)
            inserir(&(*arvore)->d,chave);
    }
}

void imprime_in_order(No* arvore){

    if(arvore!=NULL)
    {
        imprime_in_order(arvore->e);
        cout<<" "<<arvore->value;
        imprime_in_order(arvore->d);
    }
}


void imprime_in_pos_ordem(No* arvore){

    if(arvore!=NULL){
        imprime_in_order(arvore->d);
        imprime_in_order(arvore->e);
        cout<<" "<<arvore->value;
    }
}

void imprime_pre_order(No* arvore){

    if(arvore!=NULL){
        cout<<" "<<arvore->value;
        imprime_in_order(arvore->d);
        imprime_in_order(arvore->e);
    }
}

bool busca(No* arvore,int V){
    bool resultado;

    if(arvore==NULL)
        resultado=false;
    else{
        if(arvore->value==V)
            resultado= true;
        else
            {
            if(V<arvore->value)
                resultado=busca(arvore->e,V);
            else
                resultado=busca(arvore->d,V);
        }
    }
    return resultado;
}

int procure_por_NULL(No* arvore){

    if(arvore==NULL)
        return 0;

    else{
        return procure_por_NULL(arvore->e)+procure_por_NULL(arvore->d)+1;
    }

}






int main(){

    No* arvore;
    criar_arvore(&arvore);
    if(arvore==NULL)
        cout<<"teste";

    inserir(&arvore,5);
    inserir(&arvore,2);
    inserir(&arvore,12);
    inserir(&arvore,17);
    imprime_in_order(arvore);

    int n;
    cin>>n;
    if(busca(arvore,n)==false)
        cout<<endl<<"Nao encontrou";
    else{
        if(busca(arvore,n)==true)
        cout<<endl<<" encontrou";
    }

    cout<<endl<<"total de nos"<<endl<<procure_por_NULL(arvore);


    return 0;

}
