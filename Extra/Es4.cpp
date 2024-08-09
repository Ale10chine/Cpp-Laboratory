#include <iostream>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()

using namespace std;

/*
	Scrivere un programma che chieda all'utente di definire la dimensione n di una
	coppia di array paralleli (controllando che sia 10 <= n <= 100). Caricare i due array
	con numeri pseudocasuali tra 2 e 299, e visualizzare alla fine solo le coppie di
	numeri A[i] e B[i] che sono entrambi dispari (esempio di output: “All'indice 10 sono
	memorizzati i numeri dispari 31 e 47”    
*/

int main(){
	
	int dim;
	
	do{
		cout<<"Inserisci un vlore compreso tra 10 e 100"<<endl;
		cin>> dim;
	}while(dim > 100 or dim < 10);
	
	int a[dim];
	int b[dim];
	
	
	srand(static_cast<unsigned>(time(nullptr))); 
	
	//Riempo gli array con numeri pseudocasuali compresi nell'intervallo tra 2 e 299
	for(int i = 0; i < dim; i++){
		a[i] = 2 + (rand() % (299 - 2 + 1));
		b[i] = 2 + (rand() % (299 - 2 + 1));
	} 
	
	//Stampa dei numeri per ciascun array
	cout<<"---------------Primo array----------------"<<endl;
	for(int i = 0; i < dim; i++){
		cout<<i+1<<") "<<a[i]<<endl;
	} 
	cout<<"--------------Secondo array----------------"<<endl;
	
	for(int i = 0; i < dim; i++){
		cout<<i+1<<") "<<b[i]<<endl;
	} 
	
	cout<<"\n\n";
	
	//Controllo degli indici paralleli 
	for(int i = 0; i < dim; i++){
		if(a[i] % 2 != 0 and b[i] % 2 != 0) cout<<"All'indice "<<i+1<<" entrambi i numeri sono dispari"<<endl;
	}
	
	return 0;
}

/*
	for(int i = 0; i < dim; i++){
		cout<<a[i]<<endl;
	} 
	cout<<"Secondo array----------------"<<endl;
	
	for(int i = 0; i < dim; i++){
		cout<<b[i]<<endl;
	} 
*/