/*3) Elabore um algoritmo que calcule a �rea de tr�s pol�gonos: Quadrado, tri�ngulo e

trap�zio. O programa deve dar a op��o de escolha ao usu�rio e, ap�s feita a sele��o do

pol�gono, seu m�todo deve pedir as medidas necess�rias para o c�lculo da �rea de cada

uma das op��es.

Para o c�lculo das �reas devem ser implementadas quatro fun��es distintas, aplicando-se

necessariamente a sobrecarga de fun��es, onde o retorno ser� um valor float com o

resultado do c�lculo. O retorno deve ser apresentado no bloco principal com 3 casas de

precis�o ap�s a v�rgula.*/



#include<iostream>
using namespace std;

class quadrado{
private:
        float side;
public:
        void setValues(){cin>>side;}
        float getArea(){return (side*side);}
};

class triangulo{
private:
        float base,height;
public:
        float getArea(){return(base*height/2);}
        void setvalues(){cin>>base>>height;}
};

class trapezio{
private:
    float smallBase, bigBase, height;
public:
    float getArea(){return((smallBase+bigBase)*height/2);}
    void setValues(){cin>>smallBase>>bigBase>>height;}
};



int main()
{
    

    string escolha;
    cout<<"quadrado, triangulo ou trapezio?";
    cin>>escolha;
    float Area=0;
    if(escolha.compare("quadrado")==0){
        quadrado chosen;
        cout<<"Entre com o lado"<<endl;
        chosen.setValues();
        Area=chosen.getArea();}

    if(escolha.compare("triangulo")==0){
        triangulo chosen;
        cout<<"Entre com a base e a altura:"<<endl;
        chosen.setvalues();
        Area=chosen.getArea();
    }
    if(escolha.compare("trapezio")==0){
        trapezio chosen;
        cout<<"Entre com a base menor, base maior e a altura"<<endl;
        chosen.setValues();
        Area=chosen.getArea();
    }

    cout<<endl<<"A area eh: "<<Area;
    return 0;
}
