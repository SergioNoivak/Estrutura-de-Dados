/*3) Elabore um algoritmo que calcule a área de três polígonos: Quadrado, triângulo e

trapézio. O programa deve dar a opção de escolha ao usuário e, após feita a seleção do

polígono, seu método deve pedir as medidas necessárias para o cálculo da área de cada

uma das opções.

Para o cálculo das áreas devem ser implementadas quatro funções distintas, aplicando-se

necessariamente a sobrecarga de funções, onde o retorno será um valor float com o

resultado do cálculo. O retorno deve ser apresentado no bloco principal com 3 casas de

precisão após a vírgula.*/



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
