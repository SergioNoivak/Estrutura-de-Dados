/*Aqui observamos um treinamento com ponteiros em C/C++ */


#include<iostream>
using namespace std;

void entrada(char* texto, int tamanho){

for(int i=0; i<tamanho;i++)cin>>texto[i];

}

void exibeMaior(char* texto, int tamanho){
char* maior;
maior=new char[tamanho];

for(int i=0; i<tamanho;i++)
{


 maior[i]=texto[i]-32;
 }

 for(int i=0; i<tamanho;i++)cout<<maior[i];

}

int main(){

 int tamanho;
 cin>>tamanho;
 char* texto;
 texto=new char[tamanho];
 entrada(texto,tamanho);

 exibeMaior(texto,tamanho);



return 0;
}
