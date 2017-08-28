#include<iostream>
using namespace std;

int binarySearch_RECURSIVE(int* V,int key, int inicio, int fim) {
    int meio = (inicio+fim)/2;
    if(V[meio]==key)
        return meio;
    if(inicio==fim)
        return -1;
    if(V[meio]>key)
        return binarySearch(V,key,inicio,meio-1);
    if(V[meio]<key)
        return binarySearch(V,key,meio+1,fim);
}

int binarySearch_ITERATIVE(int* V,int key, int inicio, int fim){
    while(inicio<fim){
    int meio=(inicio+fim)/2;
    if(V[meio]==key){
        return key
    }
    if(V[meio]>key)
        inicio=meio+1;
    else(V[meio]<key)
        fim=meio;
    }
    return -1;
}

int main() {

    int vet[]={1,2,3,4,7,8,9,111,200000};
    ///TODO tests
}
