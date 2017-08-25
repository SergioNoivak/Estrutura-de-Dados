
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

    if(arvore!=NULL){
        cout<<" "<<arvore->value;
        imprime_in_order(arvore->e);
        imprime_in_order(arvore->d);

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

    return 0;

}
