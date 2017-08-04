#include<iostream>

using namespace std;

int main()
{
    //Podemos ver que as variáveis dentro de uma enumeracao sao decaradas

    enum seq{a=10,b=20,c=30};
    seq variavel1;
    cout<<(variavel1=a);
    int *p;
    
    //cout<<a<<b<<c;

return 0;
}
