#include<iostream>
#include<stdlib.h>
using namespace std;

//Simples alteracao
struct NO {
    int info;
    int alt;
    struct NO* esq;
    struct NO* dir;
};

int alt_NO(struct NO* no) {
    return no->alt;
}

int fatorBalanceamento_NO(struct NO* no) {

    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int a, int b) {

    if(a>b)
        return a;
    else return b;

}


/**

    Sempre eh balanceado o ancestral mais proximo do no inserido
    onde o fator de balanceamento passa a ser -2 ou +2
    esse(no com fatorBalanceamento_NO com -2 ou +2) eh o parametro para as funcoes
    implementadas.

    as rotacoes simples (LL e RR) atualizam as alturas da arvore;

    as rotacoes duplas podem ser implementadas por 2 rotacoes simples


*/


/**



        A  raiz                    A  raiz           B    altura= maior(altura(A),altura(C)+1)
       / \                        / \               / \
  no  B   E         ===> no B    D   E      ===>   C   A (altura = maior(altura(D),altura(E)+1))
     /\                     /\                    /   / \
    C  D                   C  D                  x   D   E
   /                      /
  x                      x

*/


void RotacaoLL(NO** raiz) {

    struct NO* no= (*raiz)->esq;
    (*raiz)->esq=no->dir;
    no->dir=(*raiz);
    (*raiz)->alt=maior(alt_NO((*raiz)->esq),
                       alt_NO((*raiz)->dir)
                       +1);
    no->alt = maior(alt_NO(no->esq),alt_NO((*raiz)->alt)+1);
    *raiz = no;

}

int main() {
}
