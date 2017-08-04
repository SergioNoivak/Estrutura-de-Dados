#include<iostream>


using namespace std;

///Busca Sequencial

template<typename T>
T busca_sequencial(T* vetor, T elemento, int sizeOfVetor){

    int i=0;
    int index=-1;
    bool achei=false;


    while(achei==false && i<sizeOfVetor)
    {
        if(vetor[i]==elemento){
                                achei=true;
                               index=i;
                               break;}
        else i++;

    }

    switch(achei){
                    case true: return index;
                    case false: return -1;}
}

void quickSort(int *vet, int comeco, int fim){
    int pivot, aux;
	int i, j;

	pivot = vet[(comeco+fim)/2];
	i = comeco;
	j = fim;

    for(int i=0;i<6;i++)cout<<" "<<vet[i];

	cout<<endl<<"primeiro pivot: "<<pivot<<endl;
	cout<<"i: "<<i<<endl;
	cout<<"j: "<<j<<endl;


	while(i <= j){
		while(vet[i] < pivot)
			i++;
		while(vet[j] > pivot)
			j--;
        cout<<endl;
		if(i <= j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;j--;
			cout<<endl<<"trocou vet["<<i<<"] com vet["<<j<<"] "<<endl;

            for(int i=0;i<6;i++){if(i==5) cout<<" "<<vet[i]<<endl;
                                else cout<<" "<<vet[i];}
        }
            cout<<endl<<"passo2: "<<endl;
            for(int i=0;i<6;i++){if(i==5) cout<<" "<<vet[i]<<endl;
                                else cout<<" "<<vet[i];}

	}

	if(j > comeco)
		quickSort(vet, comeco, j);

	if(i < fim)
		quickSort(vet, j+1, fim);
}



int main(){

    int vetor[]= {2,50,40,3,20,5};

    for(int i=0;i<6;i++)cout<<" "<<vetor[i]<<" ";

    cout<<endl<<"Comecando a ordenação :"<<endl<<endl;
    quickSort(vetor,0,5);

    for(int i=0;i<6;i++)cout<<" "<<vetor[i];







}
